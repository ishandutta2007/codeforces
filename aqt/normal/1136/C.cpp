#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1005][505];

int main(){
    cin >> N >> M;
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> arr[i+j][j];
        }
    }
    bool b = 1;
    int len = min(N, M);
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            int n;
            cin >> n;
            for(int k = 1; k<=501; k++){
                if(arr[i+j][k] == n){
                    arr[i+j][k] = 0;
                    break;
                }
                else if(k == 501){
                    b = 0;
                }
            }
        }
    }
    if(b){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}