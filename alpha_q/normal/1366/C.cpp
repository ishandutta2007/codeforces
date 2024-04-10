#include <bits/stdc++.h>

using namespace std;

int t, n, m, g[69][69];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", g[i] + j);
      }
    }
    int len = n + m - 1, ans = 0;
    for (int i = 1, j = len; i < j; ++i, --j) {
      int zero = 0, one = 0;
      for (int x = 1, y = i; y >= 1; ++x, --y) {
        if (x > 0 and y > 0 and x <= n and y <= m) g[x][y] ? ++one : ++zero;
      }
      for (int x = n + 1 - i, y = m; x <= n; ++x, --y) {
        if (x > 0 and y > 0 and x <= n and y <= m) g[x][y] ? ++one : ++zero;  
      }
      ans += min(zero, one);
    }
    cout << ans << '\n';
  }
  return 0;
}