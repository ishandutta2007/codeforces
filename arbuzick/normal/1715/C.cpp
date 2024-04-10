#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            ans += (i + 1) * 1LL * (n - i);
        } else {
            ans += n - i;
        }
    }
    while (m--) {
        int i, x;
        cin >> i >> x;
        i--;
        if (i != 0) {
            if (a[i] == a[i - 1]) {
                ans -= (n - i);
            } else {
                ans -= (i + 1) * 1LL * (n - i);
            }
        }
        if (i + 1 != n) {
            if (a[i] == a[i + 1]) {
                ans -= (n - i - 1);
            } else {
                ans -= (i + 2) * 1LL * (n - i - 1);
            }
        }
        a[i] = x;
        if (i != 0) {
            if (a[i] == a[i - 1]) {
                ans += (n - i);
            } else {
                ans += (i + 1) * 1LL * (n - i);
            }
        }
        if (i + 1 != n) {
            if (a[i] == a[i + 1]) {
                ans += (n - i - 1);
            } else {
                ans += (i + 2) * 1LL * (n - i - 1);
            }
        }
        cout << ans << '\n';
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