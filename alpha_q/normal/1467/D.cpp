#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5005;
const int MOD = 1e9 + 7;

int n, k, q, path[N][N], a[N], coeff[N];

int main() {
  cin >> n >> k >> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    path[0][i] = 1;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      path[i][j] = (j > 1 ? path[i - 1][j - 1] : 0) + (j < n ? path[i - 1][j + 1] : 0);
      if (path[i][j] >= MOD) path[i][j] -= MOD;
      // cerr << i << " " << j << " --> " << path[i][j] << '\n';
    }
  }
  for (int j = 1; j <= n; ++j) {
    for (int i = 0; i <= k; ++i) {
      coeff[j] = (coeff[j] + (ll) path[i][j] * path[k - i][j]) % MOD;
    }
    // cerr << coeff[j] << " ";
  }
  // cerr << '\n';
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + (ll) coeff[i] * a[i]) % MOD;
  }
  while (q--) {
    int i, x;
    scanf("%d %d", &i, &x);
    ans = (ans - (ll) coeff[i] * a[i]) % MOD;
    a[i] = x;
    ans = (ans + (ll) coeff[i] * a[i]) % MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);
  }
  return 0;
}