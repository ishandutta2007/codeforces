#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0, st = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ans += st;
            st = 0;
        } else {
            st = 1;
        }
    }
    ans += st;
    cout << min(ans, 2) << '\n';
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