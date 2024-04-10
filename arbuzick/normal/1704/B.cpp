#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int mn = a[0], mx = a[0];
    for (int i = 0; i < n; ++i) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if (mx - mn > x * 2) {
            ans++;
            mn = mx = a[i];
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