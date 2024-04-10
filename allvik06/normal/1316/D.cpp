#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector <pair <int, int>>> a;
vector <vector <char>> ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector <vector <bool>> used;
char r(pair <int, int> x, pair <int, int> y) {
    if (x.first > y.first) return 'U';
    if (x.first < y.first) return 'D';
    if (x.second < y.second) return 'R';
    if (x.second > y.second) return 'L';
}


int dfs1(int x, int y, pair <int, int> t) {
    used[x][y] = true;
    int kol = 1;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
        if (a[tx][ty] != t || used[tx][ty]) continue;
        kol += dfs1(tx, ty, t);
        ans[tx][ty] = r({tx, ty}, {x, y});
    }
    return kol;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n, vector <pair <int, int>> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j].first >> a[i][j].second;
            if (a[i][j].first != -1) {
                --a[i][j].first;
                --a[i][j].second;
            }
        }
    }
    used.resize(n, vector <bool> (n, false));
    ans.resize(n, vector <char> (n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!used[i][j] && a[i][j] == make_pair(-1, -1)) {
                bool flag = false;
                for (int k = 0; k < 4; ++k) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                    if (a[tx][ty] != make_pair(-1, -1)) continue;
                    if (used[tx][ty]) {
                        ans[i][j] = r({i, j}, {tx, ty});
                        used[i][j] = true;
                        flag = true;
                        break;
                    }
                    else {
                        used[i][j] = true;
                        used[tx][ty] = true;
                        ans[i][j] = r({i, j}, {tx, ty});
                        ans[tx][ty] = r({tx, ty}, {i, j});
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    cout << "INVALID";
                    return 0;
                }
            }
        }
    }
    map <pair <int, int>, int> d;
    vector <pair <int, int>> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != make_pair(-1, -1)) {
                ++d[a[i][j]];
                b.push_back({a[i][j]});
            }
        }
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (pair <int, int> i : b) {
        if (dfs1(i.first, i.second, i) != d[i] || a[i.first][i.second] != i) {
            cout << "INVALID";
            return 0;
        }
        ans[i.first][i.second] = 'X';
    }
    cout << "VALID\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}