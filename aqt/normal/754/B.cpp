#include <bits/stdc++.h>

using namespace std;

int N = 4;
char arr[4][4];
bool chk(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(i+2 < N && arr[i][j] == 'x' && arr[i+1][j] == 'x' && arr[i+2][j] == 'x'){
                return 1;
            }
            if(j+2 < N && arr[i][j] == 'x' && arr[i][j+1] == 'x' && arr[i][j+2] == 'x'){
                return 1;
            }
            if(i+2 < N && j+2 < N && arr[i][j] == 'x' && arr[i+1][j+1] == 'x' && arr[i+2][j+2] == 'x'){
                return 1;
            }
            if(i-2 >= 0 && j+2 < N && arr[i][j] == 'x' && arr[i-1][j+1] == 'x' && arr[i-2][j+2] == 'x'){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(arr[i][j] == '.'){
                arr[i][j] = 'x';
                if(chk()){
                    cout << "YES" << endl;
                    return 0;
                }
                arr[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl;
}