#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(4));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        dp[i] = dp[i - 1];
        if (a == 1) {
            dp[i][0] = dp[i - 1][0] + 1;
            int s = max(dp[i - 1][1], dp[i - 1][2]) + 1;
            dp[i][2] = max(dp[i][2], s);
        } else {
            int s = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][1] = max(dp[i][1], s);
            s = max(dp[i - 1][2], dp[i - 1][3]) + 1;
            dp[i][3] = max(dp[i][3], s);
        }
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}