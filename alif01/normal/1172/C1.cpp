#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
inline int qpow(int b, int p) {
  int r = 1;
  for (; p; p >>= 1) {
    if (p & 1) r = (ll) r * b % mod;
    b = (ll) b * b % mod;
  }
  return r;
}
int n, m, a[200233], w[200233], sa, sb;
int f[3033][3033], g[3033][3033];

void dp(int i, int j) {
  if (~f[i][j]) return;
  if (i + j == m) {
    f[i][j] = g[i][j] = 1;
    return;
  }
  int inv = qpow(sa + sb + i - j, mod - 2);
  if (j == sb) {
    dp(i + 1, j);
    f[i][j] = (ll) (sa + i + 1) * inv % mod * f[i + 1][j] % mod;
    g[i][j] = g[i + 1][j];
  } else {
    dp(i + 1, j);
    dp(i, j + 1);
    f[i][j] = ((ll) (sa + i + 1) * inv % mod * f[i + 1][j] + (ll) (sb - j) * inv % mod * f[i][j + 1]) % mod;
    g[i][j] = ((ll) (sa + i) * inv % mod * g[i + 1][j] + (ll) (sb - j - 1) * inv % mod * g[i][j + 1]) % mod;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    (a[i] ? sa : sb) += w[i];
  }
  memset(f, -1, sizeof f);
  dp(0, 0);
  for (int i = 1; i <= n; i++) {
    w[i] = (ll) w[i] * (a[i] ? f[0][0] : g[0][0]) % mod;
    printf("%d\n", w[i]);
  }
}