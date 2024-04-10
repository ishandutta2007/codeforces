#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e18;
int n, m;
void bfs(vector <vector <char>> &a, vector <vector <int>> &d, char c) {
    queue <pair <int, int>> q, q1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == c) {
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!q.empty() || !q1.empty()) {
        if (q.empty()) {
            swap(q, q1);
        }
        pair <int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = now.first + dx[i], y = now.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            if (a[x][y] == '#') {
                continue;
            }
            int r = (a[x][y] == '.');
            if (d[now.first][now.second] + r < d[x][y]) {
                d[x][y] = d[now.first][now.second] + r;
                if (r == 0) {
                    q.push({x, y});
                }
                else {
                    q1.push({x, y});
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector <vector <int>> d1(n, vector <int> (m, INF)), d2(n, vector <int> (m, INF)), d3(n, vector <int> (m, INF));
    bfs(a, d1, '1');
    bfs(a, d2, '2');
    bfs(a, d3, '3');
    int minn = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            minn = min(minn, d1[i][j] + d2[i][j] + d3[i][j] - 2 * (a[i][j] == '.'));
        }
    }
    if (minn == INF) {
        cout << -1;
    }
    else {
        cout << minn;
    }
    return 0;
}