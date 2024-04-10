#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

string g[N];
int q, n, m, ro[N], co[N];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> q;
  while (q--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> g[i];
    for (int i = 0; i < n; ++i) {
      ro[i] = 0;
      for (int j = 0; j < m; ++j) ro[i] += g[i][j] == '.';
    }
    for (int i = 0; i < m; ++i) {
      co[i] = 0;
      for (int j = 0; j < n; ++j) co[i] += g[j][i] == '.';
    }
    int ans = n * m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int here = ro[i] + co[j] - (g[i][j] == '.');
        ans = min(ans, here);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}