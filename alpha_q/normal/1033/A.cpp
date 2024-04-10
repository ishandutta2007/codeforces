#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1005;

int dx[] = {+1, +1, -1, -1, +1, -1, 0, 0};
int dy[] = {+1, -1, +1, -1, 0, 0, +1, -1};
int n, g[N][N], ax, ay, bx, by, cx, cy, v[N][N];

inline bool valid (int x, int y) {
  return x > 0 and y > 0 and x <= n and y <= n and g[x][y] == 0;
}

void dfs (int x, int y) {
  v[x][y] = 1;
  for (int i = 0; i < 8; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (valid(nx, ny) and !v[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  cin >> n;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;

  int x, y;

  x = ax, y = ay;
  while (x > 0) g[x][y] = 1, --x;
  x = ax, y = ay;
  while (y > 0) g[x][y] = 1, --y;
  x = ax, y = ay;
  while (x <= n) g[x][y] = 1, ++x;
  x = ax, y = ay;
  while (y <= n) g[x][y] = 1, ++y;

  x = ax, y = ay;
  while (x > 0 and y > 0) g[x][y] = 1, --x, --y;
  x = ax, y = ay;
  while (x <= n and y <= n) g[x][y] = 1, ++x, ++y;
  x = ax, y = ay;
  while (x > 0 and y <= n) g[x][y] = 1, --x, ++y;
  x = ax, y = ay;
  while (x <= n and y > 0) g[x][y] = 1, ++x, --y;

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << g[i][j];
  //   }
  //   cout << endl;
  // }

  dfs(bx, by);
  cout << (v[cx][cy] ? "YES" : "NO") << '\n';
  return 0;
}