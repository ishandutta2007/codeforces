#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    bool ch = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cnt += a[i][j] - '0';
            if (i + 1 < n && a[i + 1][j] == '0' && a[i][j] == '0') {
                ch = true;
            }
            if (j + 1 < m && a[i][j + 1] == '0' && a[i][j] == '0') {
                ch = true;
            }
            if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '0' && a[i][j] == '0') {
                ch = true;
            }
            if (i > 0 && j + 1 < m && a[i - 1][j + 1] == '0' && a[i][j] == '0') {
                ch = true;
            }
        }
    }
    if (ch) {
        cout << cnt << '\n';
    } else if (cnt < n * m) {
        cout << cnt - 1 << '\n';
    } else {
        cout << cnt - 2 << '\n';
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