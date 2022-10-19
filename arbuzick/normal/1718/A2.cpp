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
    map<int, int> val;
    for (int i = 1; i <= n; ++i) {
        val[pr[i]] = n + 10;
    }
    val[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + 1;
        dp[i + 1] = min(dp[i + 1], val[pr[i + 1]] + i);
        val[pr[i + 1]] = min(val[pr[i + 1]], dp[i + 1] - i - 1);
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