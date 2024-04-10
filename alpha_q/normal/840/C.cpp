#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 305;
const int MOD = 1e9 + 7;

bitset <N> vis;
int n, m, a[N], p[N], s[N];
ll fac[N], c[N][N], f[N][N];

bool isSquare (ll x) {
  ll r = sqrt(x);
  return r * r == x;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    p[++m] = 1, vis[i] = 1;
    for (int j = i + 1; j <= n; ++j) {
      if (vis[j]) continue;
      if (isSquare(a[i] * 1LL * a[j])) {
        ++p[m], vis[j] = 1;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    s[i] = s[i - 1] + p[i];
  }
  for (int i = 0; i < N; ++i) {
    c[i][0] = 1;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  fac[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = (i * 1LL * fac[i - 1]) % MOD;
  }
  f[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= max(0, s[i - 1] - 1); ++j) {
      for (int places = 1; places <= min(1 + s[i - 1], p[i]); ++places) {
        for (int bad = 0; bad <= min(j, places); ++bad) {
          ll one = (c[j][bad] * c[1 + s[i - 1] - j][places - bad]) % MOD;
          ll two = (c[p[i] - 1][places - 1] * f[i - 1][j]) % MOD;
          ll add = (one * two) % MOD;
          add *= fac[p[i]], add %= MOD;
          f[i][j - bad + p[i] - places] += add;
          f[i][j - bad + p[i] - places] %= MOD;
        }
      }
    }
  }
  // for (int i = 1; i <= m; ++i) {
  //   for (int j = 0; j < s[i]; ++j) {
  //     cout << i << ", " << j << endl;
  //     cout << f[i][j] << endl;
  //   }
  // }
  printf("%lld\n", f[m][0]);
  return 0;
}