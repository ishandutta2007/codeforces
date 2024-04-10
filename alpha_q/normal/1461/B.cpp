#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char g[N][N];
int t, n, m, pf[N][N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", g[i] + 1);
      for (int j = 1; j <= m; ++j) {
        pf[i][j] = pf[i][j - 1] + (g[i][j] == '.');
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int cur = i, l = j, r = j, tot = 0;
        while (cur <= n and l >= 1 and r <= m and pf[cur][r] == pf[cur][l - 1]) ++cur, ++tot, --l, ++r;
        ans += tot;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}