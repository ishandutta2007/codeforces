#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << (n - 1) / 2 << '\n';
    } else {
        int ans = 0;
        for (int i = 1; i + 1 < n; ++i) {
            if (a[i] > a[i - 1] + a[i + 1]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
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