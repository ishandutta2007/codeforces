#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char g[N][N];
int n, m, t, d[N][N];

int main() {
  cin >> n >> m >> t;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  memset(d, -1, sizeof d);
  queue <pair <int, int>> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      bool ok = 0;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x > 0 and y > 0 and x <= n and y <= m and g[x][y] == g[i][j]) {
          ok = 1;
          break;
        }
      }
      if (ok) q.emplace(i, j), d[i][j] = 0;
    }
  }
  while (!q.empty()) {
    int i = q.front().first, j = q.front().second; q.pop();
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k], y = j + dy[k];
      if (x > 0 and y > 0 and x <= n and y <= m and d[x][y] == -1) {
        d[x][y] = d[i][j] + 1;
        q.emplace(x, y);
      }
    }
  }
  while (t--) {
    int x, y;
    long long p; 
    scanf("%d %d %lld", &x, &y, &p);
    if (d[x][y] == -1 or p <= d[x][y] or (p - d[x][y]) % 2 == 0) putchar(g[x][y]);
    else putchar(g[x][y] ^ 1); puts("");
  }
  return 0;
}