#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    int ans = m;
    for (int i = 1; i <= m; i = min(i * 10LL, (long long)m + 1)) {
        ans = min(ans, m - i);
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