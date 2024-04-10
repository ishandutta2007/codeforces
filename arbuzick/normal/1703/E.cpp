#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += min(a[i][j] + a[j][n - i - 1] + a[n - i - 1][n - j - 1] + a[n - j - 1][i], 4 - (a[i][j] + a[j][n - i - 1] + a[n - i - 1][n - j - 1] + a[n - j - 1][i]));
        }
    }
    cout << ans / 4 << '\n';
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