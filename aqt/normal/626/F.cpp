#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[205];
int dp[205][205][1005];
long long MOD = 1e9+7;

int add(long long a, long long b){
    return (a+b)%MOD;
}

int mult(long long a, long long b){
    return (a*b)%MOD;
}

int main(){
    cin >> N >> K;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    dp[1][0][0] = 1;
    for(int i = 1; i<N; i++){
        int d = arr[i+1]-arr[i];
        for(int j = 0; j<=N; j++){
            for(int k = 0; k<=K; k++){
                if(j*d+k <= K){
                    dp[i+1][j][j*d+k] =
                    add(dp[i+1][j][j*d+k], mult(j+1, dp[i][j][k]));
                }
                if(j && (j-1)*d+k <= K){
                    dp[i+1][j-1][(j-1)*d+k] =
                    add(dp[i+1][j-1][(j-1)*d+k], mult(j, dp[i][j][k]));
                }
                if((j+1)*d+k <= K){
                    dp[i+1][j+1][(j+1)*d+k] =
                    add(dp[i+1][j+1][(j+1)*d+k], mult(1, dp[i][j][k]));
                }
                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }
    int ans = 0;
    for(int k = 0; k<=K; k++){
        ans = add(ans, add(dp[N][0][k], dp[N][1][k]));
    }
    cout << ans << endl;
}