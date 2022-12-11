#include <bits/stdc++.h>

using namespace std;

int N;
long long I, K, X;
long long dp[1005][10005];
int cap[1005];
long long cst[1005];

int main(){
    cin >> N >> I >> K >> X;
    for(int i = 1; i<=N; i++){
        cin >> cap[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> cst[i];
    }
    for(int i = 0; i<=N; i++){
        dp[i][0] = I;
        for(int j = 1; j<=10000; j++){
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=10000; j++){
            for(int k = 0; k<=min(j, cap[i]); k++){
                if(dp[i-1][j-k] >= 0){
                    dp[i][j] = max(dp[i][j], min(dp[i-1][j-k] + X, (j-k)*K + I)-k*cst[i]);
                }
            }
            if(dp[i][j] >= 0){
                ans = j;
            }
        }
    }
    cout << ans << endl;
}