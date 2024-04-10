#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[3][100005];
long long dp[3][100005];

long long z(int i){
    return arr[0][i] + arr[0][i-1] + arr[1][i] + arr[1][i-1] + arr[2][i] + arr[2][i-1];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<3; i++){
        for(int j = 1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][1] = arr[0][1];
    dp[1][1] = dp[0][1] + arr[1][1];
    dp[2][1] = dp[1][1] + arr[2][1];
    for(int i = 2; i<=N; i++){
        dp[0][i] = dp[0][i-1] + arr[0][i];
        dp[0][i] = max(dp[0][i], dp[1][i-1] + arr[1][i] + arr[0][i]);
        dp[0][i] = max(dp[0][i], dp[2][i-1] + arr[2][i] + arr[1][i] + arr[0][i]);
        dp[1][i] = dp[1][i-1] + arr[1][i];
        dp[1][i] = max(dp[1][i], dp[2][i-1] + arr[2][i] + arr[1][i]);
        dp[1][i] = max(dp[1][i], dp[0][i-1] + arr[0][i] + arr[1][i]);
        dp[2][i] = dp[2][i-1] + arr[2][i];
        dp[2][i] = max(dp[2][i], dp[1][i-1] + arr[1][i] + arr[2][i]);
        dp[2][i] = max(dp[2][i], dp[0][i-1] + arr[0][i] + arr[1][i] + arr[2][i]);
        dp[2][i] = max(dp[2][i], dp[0][i-2] + z(i));
        dp[0][i] = max(dp[0][i], dp[2][i-2] + z(i));
    }
    cout << dp[2][N] << endl;
}