#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1) / a) * 1LL * ((m + a - 1) / a) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}