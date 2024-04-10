#include <bits/stdc++.h>

using namespace std;

int n, m;
string g[69];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> g[i];
  int ans = 0, x = 0, y = 0;
  if (g[x][y] == '*') ++ans;
  while (true) {
    int far = 696969, nx, ny;
    for (int i = x; i < n; ++i) {
      for (int j = y; j < m; ++j) {
        if (i == x and j == y) continue;
        if (g[i][j] == '*') {
          int cur_d = i - x + j - y;
          if (cur_d < far) far = cur_d, nx = i, ny = j;
        }
      }
    }
    if (far > 6969) break;
    x = nx, y = ny, ++ans;
  }
  cout << ans << '\n';
  return 0;
}