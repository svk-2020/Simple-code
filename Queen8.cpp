#include <iostream>
#include <vector>

using namespace std;

int cell;
int counter = 0;
vector <int> solution;

//=====================================================================
void PrintSolution() {
    for (int i = 0; i < cell * 2; i++ ) {
        cout << solution[i] << " ";
    }
    cout << endl;
}
//=====================================================================
// проверка клетки на взятие в ней ферзя другими ферзями
bool LegalPosition(int row1, int col1) {    
    bool capture = false;
    for (size_t i = 0; i < solution.size(); i = i + 2) {
        int row = solution[i];
        int col = solution[i+1];
        if ((row1 == row) or (abs(row1 - row) == abs(col1 - col))) {
            capture = true;
            break;
        }
    }
    return not capture;
}
//=====================================================================
int FindQueens(int col) {            
    int next_col = col + 1;   
    for (int next_row = 0; next_row < cell; next_row++) {
        if (LegalPosition(next_row, next_col)) {
            solution.push_back(next_row);
            solution.push_back(next_col);
            if (next_col == cell - 1) {
                counter++;
                PrintSolution();
                solution.pop_back();
                solution.pop_back();                
            } else {
                FindQueens(next_col);
            }
        }
    }
    solution.pop_back();
    solution.pop_back();
    return 0;
}
//=====================================================================
int main() {
    cout << "   Queen8" << endl
        << "======================================================" << endl
        << "finds how many ways can be placed on the board N x N," << endl 
        << "N queens who do not beat each other." << endl 
        << "======================================================" << endl;
    cout << "Enter number N: ";
    cin >> cell;        

    if (cell == 1) {
        counter = 1;
    } else {
        for (int row = 0; row < cell; row++) {
            solution.push_back(row);
            solution.push_back(0);
            FindQueens(0);            
        }
    }
    cout << "ways found - " << counter << endl;

    return 0;
}