#include <bits/stdc++.h>

using namespace std;

int arr[4005][4005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 1; i<=N; i+=4){
        for(int j = 1; j<=N; j+=4){
            for(int a = 0; a<4; a++){
                for(int b = 0; b<4; b++){
                    arr[i+a][j+b] = cnt++;
                }
            }
        }
    }
    for(int i=  1; i<=N; i++){
        int x = 0;
        for(int j = 1; j<=N; j++){
            x ^= arr[i][j];
        }
        assert(!x);
        x = 0;
        for(int j = 1; j<=N; j++){
            x ^= arr[j][i];
        }
        assert(!x);
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}