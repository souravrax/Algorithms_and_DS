#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string goal = "ALLIZZWELL";
int visited[105][105];

int column, row;
vector<string> table;


int check(int r, int c, int a){
    
    if ( a == 10 ) return true;
    visited[r][c] = 1;
    for (int i = -1 ; i <= 1 ; ++i){
        for (int j = -1 ; j <= 1 ; ++j){
            int rowS = r+i, colS = c+j;
            if ((i == 0 && j == 0) || rowS < 0 || rowS >= column || colS < 0 || colS >= row || table[rowS][colS] != goal[a])
                continue;
            if (visited[rowS][colS])
                continue;
            if (check(rowS, colS, a+1)){
                visited[r][c] = 0;
                return true;
            }
        } // for ends
    } // for ends
    visited[r][c] = 0;
    return false;
}

int main () {
    
    string st;
    
    int t;
    cin >> t;
    
    while (t--) {
        
        table.clear();
        cin >> column >> row;
        for (int i = 0; i < column; ++i) {
            cin >> st;
            table.push_back(st);
        }
        bool res = false;
        for (int i = 0 ; i < column ; ++i)
            for (int j = 0; j < row ; ++j)
                if (table[i][j] == 'A' && check(i,j,1)){
                    res = true; break;
                }
        
        if (res)    cout << "YES" << endl;
        else        cout << "NO" << endl;
    }
    
}
