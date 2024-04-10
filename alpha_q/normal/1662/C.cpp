#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 203;
const int MOD = 998244353;

int n, m, k, deg[N];
ll g[N][N], base[N][N], temp[N][N], ret[N][N], save[N][N];

void copy (ll a[N][N], ll b[N][N]) {
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    b[i][j] = a[i][j], a[i][j] = 0;
  }
}

void mult (ll a[N][N], ll b[N][N], ll c[N][N]) {
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    for (int k = 0; k < n; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
  }
}

int main() {
  cin >> n >> m >> k; --k;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v, ++deg[u], ++deg[v];
    g[u][v] = g[v][u] = 1;
  }
  if (!k) {
    cout << 0 << '\n';
    return 0;
  }
  mult(g, g, temp);
  for (int i = 0; i < n; ++i) {
    temp[i][i] = (temp[i][i] + MOD - deg[i]) % MOD;
  }
  copy(temp, save);
  if (k == 1) {
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += save[i][i];
    ans %= MOD, ans += MOD, ans %= MOD;
    cout << ans << '\n';
    return 0;
  }
  memset(ret, 0, sizeof ret);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      base[i][j] = g[i][j];
      if (i == j) {
        base[i][n + j] = (MOD - max(0, deg[i] - 1)) % MOD;
        ret[i][j] = ret[n + i][n + j] = base[n + i][j] = 1;
      }
    }
  }
  n <<= 1;
  while (k) {
    if (k & 1) mult(ret, base, temp), copy(temp, ret);
    mult(base, base, temp), copy(temp, base), k >>= 1;
  }
  n >>= 1;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) base[i][j] = ret[n + i][j];
  }
  mult(base, save, temp);
  for (int i = 0; i < n; ++i) ans += temp[i][i];
  memset(temp, 0, sizeof temp);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) base[i][j] = ret[n + i][n + j];
  }
  mult(base, g, temp);
  for (int i = 0; i < n; ++i) ans += temp[i][i];
  ans %= MOD, ans += MOD, ans %= MOD;
  cout << ans << '\n';
  return 0;
}