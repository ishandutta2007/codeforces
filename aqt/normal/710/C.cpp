#include <bits/stdc++.h>

using namespace std;

int ans[51][51];

int main(){
    int N, cnt = 2;
    cin >> N;
    for(int i = 1; i<=N/2; i++){
        for(int j = N/2-i+1; j>0; j--){
            ans[i][j] = cnt;
            cnt += 2;
            ans[N-i+1][j] = cnt;
            cnt += 2;
            ans[i][N-j+1]= cnt;
            cnt += 2;
            ans[N-i+1][N-j+1] = cnt;
            cnt += 2;
        }
    }
    cnt = 1;
    for(int i= 1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            if(!ans[i][j]){
                ans[i][j] = cnt;
                cnt += 2;
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}