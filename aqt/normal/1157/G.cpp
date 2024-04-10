#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[205][205];
bool row[205], col[205];
bool c;
int idx;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    for(int j = 2; j<=M; j++){
        int dif = 0;
        for(int i = 1; i<=N; i++){
            dif += arr[i][j]^arr[i][j-1];
        }
        if(dif == N){
            col[j] = 1;
        }
        else if(dif == 0){

        }
        else if(dif == 1){
            if(c){
                cout << "NO" << endl;
                return 0;
            }
            c = 1;
        }
        else if(dif == N-1){
            if(c){
                cout << "NO" << endl;
                return 0;
            }
            c = 1;
            col[j] = 1;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
        if(col[j]){
            for(int i = 1; i<=N; i++){
                arr[i][j] ^= 1;
            }
        }
    }
    cout << "YES" << endl;
    bool one = 0;
    for(int i = 1; i<=N; i++){
        if(arr[i][1] == arr[i][M]){
            if(one != arr[i][1]){
                row[i] = 1;
            }
        }
        else{
            one = 1;
            if(arr[i][1] == 1){
                row[i] = 1;
            }
        }
    }
    for(int i =1 ; i<=N; i++){
        cout << row[i];
    }
    cout << endl;
    for(int i = 1; i<=M; i++){
        cout << col[i];
    }
    cout << endl;
}