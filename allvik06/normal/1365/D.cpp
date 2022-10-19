#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <char>> a(n, vector <char> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        if (a[n - 1][m - 1] == 'B') {
            cout << "No\n";
            continue;
        }
        bool flag = true;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'B') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (a[x][y] == 'G') flag = false;
                    }
                }
            }
        }
        if (!flag) {
            cout << "No\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'B') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (a[x][y] == '.') a[x][y] = '#';
                    }
                }
            }
        }
        if (a[n - 1][m - 1] == '#') {
            bool est = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] == 'G') {
                        est = true;
                    }
                }
            }
            if (est) cout << "No\n";
            else cout << "Yes\n";
            continue;
        }
        vector <vector <bool>> flex(n, vector <bool> (m));
        flex[n - 1][m - 1] = true;
        queue<pair <int, int>> q;
        q.push({n - 1, m - 1});
        while (!q.empty()) {
            pair <int, int> now = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = now.first + dx[k], y = now.second + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (a[x][y] != '#' && !flex[x][y]) {
                    q.push({x, y});
                    flex[x][y] = true;
                }
            }
        }
        bool flag1 = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'G' && !flex[i][j]) {
                    flag1 = false;
                }
            }
        }
        if (flag1) cout << "Yes\n";
        else cout << "No\n";
    }
}