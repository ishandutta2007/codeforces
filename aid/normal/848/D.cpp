#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int sum(int a, int b) {
  add(a, b);
  return a;
}

const int maxn = 55;
int f[maxn], inv[maxn], finv[maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int n, m;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

int dp[maxn][maxn], ndp[maxn][maxn], dp2[maxn][maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  memset(dp2, 0, sizeof(dp2));
  dp[0][1] = 1;
  for (int i = 0; i <= n; i++) {
    for (int l = 0; l <= i; l++) {
      for (int lf = 0; lf <= l + 1; lf++) {
        int r = i - l;
        for (int rf = 0; rf <= r + 1; rf++) {
          int f = min(lf, rf);
          add(dp2[i][f], mul(dp[l][lf], dp[r][rf]));
        }
      }
    }
    for (int f = 0; f <= i + 1; f++) {
      for (int ii = 0; ii <= n; ii++) {
        for (int j = 0; j <= ii + 1; j++) {
          ndp[ii][j] = dp[ii][j];
        }
      }
      for (int k = 1; k * (i + 1) <= n; k++) {
        int toadd = 1;
        for (int ii = 0; ii < k; ii++) {
          toadd = mul(toadd, sum(dp2[i][f], ii));
        }
        toadd = mul(toadd, finv[k]);
        for (int ii = n; ii >= 0; ii--) {
          for (int j = 0; j <= ii + 1; j++) {
            if (ii + k * (i + 1) <= n) {
              add(ndp[ii + k * (i + 1)][j + k * f], mul(dp[ii][j], toadd));
            }
          }
        }
      }
      swap(dp, ndp);
    }
  }
  printf("%d\n", dp[n][m]);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}