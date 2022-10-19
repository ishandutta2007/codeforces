#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod = 1e9 + 7;
    vector<vector<int>> dp(2000000, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 0;
    for (int i = 2; i < 2000000; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + max(dp[i - 2][0], dp[i - 2][1]) * 2;
        dp[i][1] = 4 + dp[i - 1][0] + dp[i - 2][0] * 2;
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }
    return 0;
}