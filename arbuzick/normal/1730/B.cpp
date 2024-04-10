#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    long double l = 0, r = 1e8 + 8;
    for (int _ = 0; _ < 200; ++_) {
        long double m = (l + r) / 2;
        long double tm_l = 0, tm_r = 0;
        for (int i = 0; i < n; ++i) {
            if (x[i] <= m) {
                tm_l = max(tm_l, m - x[i] + t[i]);
            } else {
                tm_r = max(tm_r, x[i] - m + t[i]);
            }
        }
        if (tm_l <= tm_r) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(25);
    cout << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}