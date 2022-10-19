#include <bits/stdc++.h>
using namespace std;

const int K = 19;
const int INF = 1e9;
int mn[2][1<<K], mx[2][1<<K], f[2][1<<K];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int m = 1<<k;
  fill(mn[0], mn[0]+m, INF);
  fill(mx[0], mx[0]+m, -INF);
  fill(f[0], f[0]+m, INF);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mn[0][a] = 0;
    mx[0][a] = 0;
  }

  for (int i = 0; i < k; i++) {
    int z = (1<<i);
    int u = i&1;
    // Restrict a to those matching j in the last k-i bits, and XOR with j.
    // Then mn[j] is the minimum, mx[j] is the maximum, and f[j] is the smallest
    // difference.
    for (int j = 0; j < m; j++) {
      mn[1-u][j] = min(mn[u][j], mn[u][j^z]^z);
      mx[1-u][j] = max(mx[u][j], mx[u][j^z]^z);
      f[1-u][j] = min({f[u][j], f[u][j^z], ((mn[u][j^z]^z)-mx[u][j])});
    }
  }

  for (int i = 0; i < m; i++) {
    cout << f[k&1][i] << ' ';
  }
  cout << '\n';
}