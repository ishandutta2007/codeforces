#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int mn = a[i][m - 1];
        int pos = -1;
        for (int j = m - 1; j >= 0; --j) {
            if (a[i][j] > mn) {
                pos = j;
            }
            mn = min(mn, a[i][j]);
        }
        if (pos != -1) {
            s.insert(pos);
        }
        int mx = a[i][0];
        pos = -1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < mx) {
                pos = j;
            }
            mx = max(mx, a[i][j]);
        }
        if (pos != -1) {
            s.insert(pos);
        }
    }
    if (s.size() == 0) {
        cout << 1 << ' ' << 1 << '\n';
    } else if (s.size() > 2) {
        cout << -1 << '\n';
    } else {
        bool ch = true;
        for (int i = 0; i < n; ++i) {
            swap(a[i][*s.begin()], a[i][*s.rbegin()]);
            for (int j = 1; j < m; ++j) {
                if (a[i][j] < a[i][j - 1]) {
                    ch = false;
                }
            }
        }
        if (ch) {
            cout << *s.begin() + 1 << ' ' << *s.rbegin() + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
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