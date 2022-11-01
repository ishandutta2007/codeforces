#include <bits/stdc++.h>

using namespace std;

const int N = 69;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char g[N][N];
int t, n, m, d[N][N];

inline bool valid (int x, int y) {
  return x > 0 and y > 0 and x <= n and y <= m;
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    vector <pair <int, int>> good, bad;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", g[i] + 1);
      for (int j = 1; j <= m; ++j) {
        if (g[i][j] == 'G') good.emplace_back(i, j);
        if (g[i][j] == 'B') bad.emplace_back(i, j);
      }
    }
    if (good.empty()) {
      puts("Yes");
      continue;
    }
    for (auto it : bad) {
      int i = it.first, j = it.second;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (valid(x, y)) g[x][y] = '#';
      }
    }
    memset(d, -1, sizeof d);
    if (g[n][m] == '#') {
      puts("No");
      continue;
    }
    queue <pair <int, int>> q;
    d[n][m] = 0, q.emplace(n, m);
    while (!q.empty()) {
      auto it = q.front(); q.pop();
      int x = it.first, y = it.second;
      for (int k = 0; k < 4; ++k) {
        int i = x + dx[k], j = y + dy[k];
        if (valid(i, j) and g[i][j] != '#' and d[i][j] == -1) {
          d[i][j] = d[x][y] + 1, q.emplace(i, j);
        }
      }
    }
    bool ok = 1;
    for (auto it : good) {
      if (d[it.first][it.second] == -1) {
        ok = 0;
        break;
      }
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}