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

void precalc() {
}

const int maxn = 1005, maxd = 11;
int n, d, mod;

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

int read() {
  if (scanf("%d%d%d", &n, &d, &mod) < 3) {
    return false;
  }
  return true;
}

int inv[maxn], finv[maxn];
int dp[maxn][maxd], ndp[maxn][maxd];

void solve() {
  if (n <= 2) {
    printf("1\n");
    return;
  }
  inv[1] = 1;
  for (int i = 2; i <= d; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i <= d; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= d; i++) {
    dp[i + 1][i] = 1;
  }
  for (int ts = 2; ts < (n + 1) / 2; ts++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= d; j++) {
        ndp[i][j] = dp[i][j];
      }
    }
    for (int k = 1; k * ts < n && k <= d; k++) {
      int tomul = finv[k];
      for (int i = 0; i < k; i++) {
        tomul = mul(tomul, sum(dp[ts][d - 1], i));
      }
      for (int i = 1; i + k * ts <= n; i++) {
        for (int j = 0; j + k <= d; j++) {
          auto cur = dp[i][j];
          if (!cur) {
            continue;
          }
          add(ndp[i + k * ts][j + k], mul(cur, tomul));
        }
      }
    }
    swap(dp, ndp);
  }
  int res = dp[n][d];
  if (!(n & 1)) {
    add(res, mul(mul(dp[n / 2][d - 1], sum(dp[n / 2][d - 1], 1)), inv[2]));
  }
  printf("%d\n", res);
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