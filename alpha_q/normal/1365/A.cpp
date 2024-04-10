#include <bits/stdc++.h>

using namespace std;

int t, n, m, g[69][69];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", g[i] + j);
      }
    }
    int ro = 0, co = 0;
    for (int i = 0; i < n; ++i) {
      int tot = 0;
      for (int j = 0; j < m; ++j) tot += g[i][j];
      if (!tot) ++ro;
    }
    for (int i = 0; i < m; ++i) {
      int tot = 0;
      for (int j = 0; j < n; ++j) tot += g[j][i];
      if (!tot) ++co;
    }
    puts((min(ro, co) & 1) ? "Ashish" : "Vivek");
  }
  return 0;
}