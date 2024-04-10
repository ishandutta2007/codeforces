#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    int ans = (1 << 20) - 1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (i != p[i]) {
            ans &= p[i];
        }
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