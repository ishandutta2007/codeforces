#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int dp[n];
    int dpp[27];
    for (int i = 0; i < 27; ++i) {
        dpp[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = s[i] - 'a' + 1; j < 27; ++j) {
            dp[i] = max(dp[i], dpp[j] + 1);
        }
        dpp[s[i] - 'a'] = dp[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    return 0;
}