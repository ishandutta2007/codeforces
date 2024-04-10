#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <char>> a(n, vector <char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int x, y, kol = 0;
    int need;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                ++kol;
                x = i;
                y = j;
            }
        }
    }
    need = kol - k;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector <vector <bool>> used(n, vector <bool> (m));
    function<void()> print = [&] {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '#') cout << '#';
                else if (a[i][j] == 'X') cout << '.';
                else cout << 'X';
            }
            cout << "\n";
        }
        exit(0);
    };
    function<void(int, int)> dfs = [&](int xx, int yy) {
        used[xx][yy] = true;
        a[xx][yy] = 'X';
        need--;
        if (need == 0) print();
        for (int k = 0; k < 4; ++k) {
            int newx = xx + dx[k];
            int newy = yy + dy[k];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || used[newx][newy] || a[newx][newy] == '#') continue;
            dfs(newx, newy);
        }
    };
    dfs(x, y);
}