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
    if ((n + m - 1) % 2 == 1) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> dp_mn(n, vector<int>(m)), dp_mx(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0 && j > 0) {
                dp_mn[i][j] = min(dp_mn[i - 1][j], dp_mn[i][j - 1]) + a[i][j];
                dp_mx[i][j] = max(dp_mx[i - 1][j], dp_mx[i][j - 1]) + a[i][j];
            } else if (i > 0) {
                dp_mn[i][j] = dp_mn[i - 1][j] + a[i][j];
                dp_mx[i][j] = dp_mx[i - 1][j] + a[i][j];
            } else if (j > 0) {
                dp_mn[i][j] = dp_mn[i][j - 1] + a[i][j];
                dp_mx[i][j] = dp_mx[i][j - 1] + a[i][j];
            } else {
                dp_mn[i][j] = dp_mx[i][j] = a[i][j];
            }
        }
    }
    if (dp_mn[n - 1][m - 1] * 1LL * dp_mx[n - 1][m - 1] <= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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