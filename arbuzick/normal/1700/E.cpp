#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    auto check = [&](int i, int j) {
        if (i < 0 || i == n || j < 0 || j == m) {
            return true;
        }
        if (a[i][j] == 0) {
            return true;
        }
        return (i > 0 && a[i - 1][j] < a[i][j]) || (i + 1 < n && a[i + 1][j] < a[i][j]) || (j > 0 && a[i][j - 1] < a[i][j]) || (j + 1 < m && a[i][j + 1] < a[i][j]);
    };
    vector<pair<int, int>> kek;
    vector<vector<int>> br(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!check(i, j)) {
                br[i][j] = 1;
                kek.emplace_back(i, j);
            }
        }
    }
    if (kek.size() == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (kek.size() > 3) {
        cout << 2 << '\n';
        return 0;
    }
    vector<pair<int, int>> lol;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (br[i][j] || (i > 0 && br[i - 1][j]) || (i + 1 < n && br[i + 1][j]) || (j > 0 && br[i][j - 1]) || (j + 1 < m && br[i][j + 1])) {
                lol.emplace_back(i, j);
            }
        }
    }
    set<pair<int, int>> s;
    for (auto [i, j] : lol) {
        for (int i2 = 0; i2 < n; ++i2) {
            for (int j2 = 0; j2 < m; ++j2) {
                swap(a[i][j], a[i2][j2]);
                bool ch = true;
                for (auto [bi, bj] : kek) {
                    if (!check(bi, bj)) {
                        ch = false;
                        break;
                    }
                }
                ch = ch && check(i, j) && check(i2, j2) && check(i - 1, j) && check(i + 1, j) && check(i, j - 1) && check(i, j + 1) && check(i2 - 1, j2) && check(i2 + 1, j2) && check(i2, j2 - 1) && check(i2, j2 + 1);
                if (ch) {
                    s.insert({min(i * m + j, i2 * m + j2), max(i * m + j, i2 * m + j2)});
                }
                swap(a[i][j], a[i2][j2]);
            }
        }
    }
    if (s.empty()) {
        cout << 2 << '\n';
    } else {
        cout << 1 << ' ' << s.size() << '\n';
    }
    return 0;
}