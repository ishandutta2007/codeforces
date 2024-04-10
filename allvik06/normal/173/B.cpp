#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(4, INF)));
    d[0][0][0] = 0;
    queue<pair<pair<int, int>, int>> q, q1;
    q.push({{0, 0}, 0});
    if (a[0][0] == '#') {
        for (int i = 1; i < 4; ++i) {
            d[0][0][i] = 1;
            q1.push({{0, 0}, i});
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty() || !q1.empty()) {
        if (q.empty()) {
            swap(q, q1);
        }
        pair<pair<int, int>, int> now = q.front();
        q.pop();
        int x = now.first.first + dx[now.second], y = now.first.second + dy[now.second];
        if (x < 0 || x >= n || y < 0 || y >= m) {
            continue;
        }
        if (d[x][y][now.second] > d[now.first.first][now.first.second][now.second]) {
            d[x][y][now.second] = d[now.first.first][now.first.second][now.second];
            q.push({{x, y}, now.second});
        }
        if (a[x][y] == '#') {
            for (int j = 0; j < 4; ++j) {
                if (d[x][y][j] > d[now.first.first][now.first.second][now.second] + 1) {
                    d[x][y][j] = d[now.first.first][now.first.second][now.second] + 1;
                    q1.push({{x, y}, j});
                }
            }
        }
    }
    if (d[n - 1][m - 1][0] == INF) {
        cout << -1;
    } else {
        cout << d[n - 1][m - 1][0];
    }
    return 0;
}