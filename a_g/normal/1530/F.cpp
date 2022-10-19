#include <bits/stdc++.h>
using namespace std;

const int MOD = 31607;
const int N = 21;
int a[N][N];
int z[N][1<<N]; // (row, mask) -> probability
int y[N]; // column -> probability

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  const int D = inversemod(1e4, MOD);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int p;
      cin >> p;
      a[i][j] = p * D % MOD;
    }
  }

  for (int i = 0; i < n; i++) {
    z[i][0] = 1;
    for (int j = 1; j < (1<<n); j++) {
      int k = j&(j-1);
      if (!k) {
        z[i][j] = a[i][31-__builtin_clz(j)];
        continue;
      }
      z[i][j] = z[i][j-k] * z[i][k] % MOD;
    }
  }

  for (int i = 0; i < n; i++) {
    y[i] = 1;
    for (int j = 0; j < n; j++) {
      y[i] = y[i] * a[j][i] % MOD;
    }
  }

  int ans = 0;
  for (int mask = 0; mask < (1<<n); mask++) {
    // mask = column events
    int sgn = (__builtin_popcount(mask)&1 ? -1 : 1);
    int b = 1;
    int e[4] = {1, 1, 1, 1};
    for (int i = 0; i < n; i++) {
      if (mask & (1<<i)) {
        b = b * y[i] % MOD;
      }
      else {
        e[1] = e[1] * a[i][i] % MOD;
        e[2] = e[2] * a[n-1-i][i] % MOD;
        if (2*i == n-1) {
          e[3] = e[3] * a[i][i] % MOD;
        }
        else {
          e[3] = e[3] * a[i][i] % MOD;
          e[3] = e[3] * a[n-1-i][i] % MOD;
        }
      }
      e[0] *= 1-z[i][(1<<n)-1-mask];
      e[1] *= 1-z[i][(1<<n)-1-(mask | (1<<i))];
      e[2] *= 1-z[i][(1<<n)-1-(mask | (1<<(n-1-i)))];
      e[3] *= 1-z[i][(1<<n)-1-(mask | (1<<i) | (1<<(n-1-i)))];
      for (int j = 0; j < 4; j++) e[j] %= MOD;
    }
    ans += sgn * b * ((e[0]-e[1]-e[2]+e[3]) % MOD) % MOD;
    ans %= MOD;
  }
  cout << (1-ans+MOD) % MOD << '\n';
}