#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200;

int n, m;
char g[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == 'B') {
        int x = i, y = j;
        while (y < m and g[x][y + 1] == 'B') {
          ++y;
        }
        int len = y - j + 1;
        len >>= 1;
        cout << (i + len) << " " << (j + len) << '\n';
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}