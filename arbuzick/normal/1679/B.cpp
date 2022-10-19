#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), tm(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tm[i] = 0;
        sum += a[i];
    }
    int evr = 0, tt = -1;
    for (int i = 1; i <= q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            if (tm[p] > tt) {
                sum += x - a[p];
            } else {
                sum += x - evr;
            }
            a[p] = x;
            tm[p] = i;
        } else {
            int x;
            cin >> x;
            evr = x;
            tt = i;
            sum = n * 1LL * evr;
        }
        cout << sum << '\n';
    }
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