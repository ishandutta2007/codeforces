#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n)), b(2, vector<int>(n));
    int bal = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            bal += a[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
            bal -= b[i][j];
        }
    }
    if (bal != 0) {
        cout << -1 << '\n';
        return 0;
    }
    bal = 0;
    int bal_up = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(bal);
        bal += a[0][i] + a[1][i] - b[0][i] - b[1][i];
        bal_up += a[0][i] - b[0][i];
        if (bal_up * 1LL * (bal - bal_up) < 0) {
            int bal_down = bal - bal_up;
            ans += min(abs(bal_up), abs(bal_down));
            if (abs(bal_up) < abs(bal_down)) {
                bal_up = 0;
            } else {
                bal_up = bal;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}