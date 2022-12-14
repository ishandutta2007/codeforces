#include <bits/stdc++.h>

using namespace std;

int dp[9000];

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp[0] = 0;
    for (int i = 0; i <= n; i++){
        if (dp[i] == 0 && i != 0)
            continue;
        dp[i + a] = max(dp[i] + 1, dp[i + a]);
        dp[i + b] = max(dp[i] + 1, dp[i + b]);
        dp[i + c] = max(dp[i] + 1, dp[i + c]);
    }
    cout << dp[n] << endl;
}