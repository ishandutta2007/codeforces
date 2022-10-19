#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (i != 0 || j != 0) {
                a[i][j]++;
            }
        }
    }
    multiset<int> ms, ms2;
    ms.insert(0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0) {
                ms.insert(a[i][j] - j);
            } else {
                ms.insert(a[i][j] - (m * 2 - j - 1));
            }
        }
    }
    int ans = *ms.rbegin() + m * 2 - 1;
    for (int j = 0; j < m; ++j) {
        ms.erase(ms.find(a[0][j] - j));
        ms.erase(ms.find(a[1][j] - (m * 2 - j - 1)));
        if (j % 2 == 0) {
            ms2.insert(a[0][j] - j * 2);
            ms2.insert(a[1][j] - (j * 2 + 1));
        } else {
            ms2.insert(a[0][j] - (j * 2 + 1));
            ms2.insert(a[1][j] - j * 2);
            ans = min(ans, max(*ms.rbegin() - j - 1, *ms2.rbegin()) + m * 2 - 1);
        }
    }
    ms.clear();
    ms.insert(0);
    ms2.clear();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 1) {
                ms.insert(a[i][j] - j);
            } else {
                ms.insert(a[i][j] - (m * 2 - j - 1));
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        ms.erase(ms.find(a[1][j] - j));
        ms.erase(ms.find(a[0][j] - (m * 2 - j - 1)));
        if (j % 2 == 0) {
            ms2.insert(a[0][j] - j * 2);
            ms2.insert(a[1][j] - (j * 2 + 1));
            ans = min(ans, max(*ms.rbegin() - j - 1, *ms2.rbegin()) + m * 2 - 1);
        } else {
            ms2.insert(a[0][j] - (j * 2 + 1));
            ms2.insert(a[1][j] - j * 2);
        }
    }
    cout << ans << '\n';
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