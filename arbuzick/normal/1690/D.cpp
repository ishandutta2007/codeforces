#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i];
        if (s[i] == 'W') {
            pr[i + 1]++;
        }
    }
    int ans = n;
    for (int i = 0; i + k <= n; ++i) {
        ans = min(ans, pr[i + k] - pr[i]);
    }
    cout << ans << '\n';
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