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

const int maxn = 5005;
int n, a, b, k;

int read() {
  if (scanf("%d%d%d%d", &n, &a, &b, &k) < 4) {
    return false;
  }
  a--;
  b--;
  return true;
}

int dp[maxn], ndp[maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[a] = 1;
  for (int it = 0; it < k; it++) {
    memset(ndp, 0, sizeof(ndp));
    for (int i = 0; i < n; i++) {
      auto cur = dp[i];
      if (!cur) {
        continue;
      }
      int d = abs(b - i) - 1;
      int l = i - d, r = i + d + 1;
      l = max(l, 0);
      r = min(r, n);
      add(ndp[l], cur);
      add(ndp[i], mod - cur);
      add(ndp[i + 1], cur);
      add(ndp[r], mod - cur);
    }
    for (int i = 1; i <= n; i++) {
      add(ndp[i], ndp[i - 1]);
    }
    swap(dp, ndp);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    add(res, dp[i]);
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