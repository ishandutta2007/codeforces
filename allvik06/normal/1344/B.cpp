#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <vector <bool>> a, used;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int i, int j) {
    used[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && !used[x][y] && a[i][j]) dfs(x, y);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.resize(n, vector <bool> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '#') a[i][j] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool f = false, s = false;
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) {
                f = true;
                if (s) {
                    cout << -1;
                    return 0;
                }
            }
            else {
                if (f) s = true;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        bool f = false, s = false;
        for (int j = 0; j < n; ++j) {
            if (a[j][i]) {
                f = true;
                if (s) {
                    cout << -1;
                    return 0;
                }
            }
            else {
                if (f) s = true;
            }
        }
    }
    vector <bool> str(n), st(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) str[i] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j][i]) st[i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool fl = str[i];
        for (int j = 0; j < m; ++j) {
            if (!str[i] && !st[j]) fl = true;
        }
        if (!fl) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        bool fl = st[i];
        for (int j = 0; j < n; ++j) {
            if (!st[i] && !str[j]) fl = true;
        }
        if (!fl) {
            cout << -1;
            return 0;
        }
    }
    int ans = 0;
    used.resize(n, vector <bool> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] && !used[i][j]) {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}