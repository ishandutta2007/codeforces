#include <bits/stdc++.h>

using namespace std;

int dp[2][505][505];
int N, M, K;
long long MOD;
int arr[505];

int main(){
    cin >> N >> M >> K >> MOD;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    dp[0][0][0] = 1;
    for(int i = 1; i<=N; i++){
        for(int j= 0; j<=M; j++){
            for(int k = 0; k<=K; k++){
                dp[i&1][j][k] = dp[i&1^1][j][k];
                if(k >= arr[i] && j){
                    dp[i&1][j][k] += dp[i&1][j-1][k-arr[i]];
                }
                dp[i&1][j][k] %= MOD;
            }
        }
    }
    long long tot = 0;
    for(int i = 0; i<=K; i++){
        tot += dp[N&1][M][i];
        tot %= MOD;
    }
    cout << tot << endl;
}