#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int st = 0;
    int m;
    cin >> m;
    while (m--) {
        int b;
        cin >> b;
        st += b;
        if (st >= n) {
            st -= n;
        }
    }
    cout << a[st] << '\n';
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