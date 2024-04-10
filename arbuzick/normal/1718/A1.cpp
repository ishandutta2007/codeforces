#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), pr(n + 1);
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pr[i + 1] = pr[i] ^ a[i];
    }
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + 1;
        for (int j = 0; j <= i; ++j) {
            if ((pr[i + 1] ^ pr[j]) == 0) {
                dp[i + 1] = min(dp[i + 1], dp[j] + i - j);
            }
        }
    }
    cout << dp[n] << '\n';
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