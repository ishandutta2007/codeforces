#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    array<string, 2> a;
    cin >> a[0] >> a[1];
    array<vector<int>, 2> dp = {vector<int>(n + 1, 0), vector<int>(n + 1, 0)};
    bool used = false;
    for (int i = 0; i < n; ++i) {
        if (!used) {
            if (a[0][i] == '*' && a[1][i] == '*') {
                dp[0][i + 1] = dp[1][i + 1] = 1;
            } else if (a[0][i] == '*') {
                dp[1][i + 1] = 1;
            } else if (a[1][i] == '*') {
                dp[0][i + 1] = 1;
            }
        } else {
            if (a[0][i] == '*' && a[1][i] == '*') {
                dp[0][i + 1] = dp[1][i + 1] = min(dp[0][i], dp[1][i]) + 2;
            } else if (a[0][i] == '*') {
                dp[0][i + 1] = min(dp[0][i] + 1, dp[1][i] + 2);
                dp[1][i + 1] = min(dp[0][i] + 2, dp[1][i] + 2);
            } else if (a[1][i] == '*') {
                dp[0][i + 1] = min(dp[0][i] + 2, dp[1][i] + 2);
                dp[1][i + 1] = min(dp[0][i] + 2, dp[1][i] + 1);
            } else {
                dp[0][i + 1] = dp[0][i] + 1;
                dp[1][i + 1] = dp[1][i] + 1;
            }
        }
        used = used || (a[0][i] == '*') || (a[1][i] == '*');
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[0][i] == '*' || a[1][i] == '*') {
            cout << min(dp[0][i + 1], dp[1][i + 1]) << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}