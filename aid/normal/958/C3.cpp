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

const int maxn = (int) 5e5 + 5, maxk = 105, maxp = 105;
int n, k, p;
int a[maxn];

int read() {
  if (scanf("%d%d%d", &n, &k, &p) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] %= p;
  }
  return true;
}

int s[maxn];
int dp[maxk][maxp], ndp[maxk][maxp];
int d[maxp];

void solve() {
  if (2 * k * p >= n) {
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j < p; j++) {
        dp[i][j] = inf;
      }
    }
    dp[0][a[0]] = 0;
    for (int i = 1; i < n; i++) {
      for (int ii = 0; ii <= k; ii++) {
        for (int j = 0; j < p; j++) {
          ndp[ii][j] = inf;
        }
      }
      for (int j = 0; j < k; j++) {
        for (int x = 0; x < p; x++) {
          auto cur = dp[j][x];
          if (cur >= inf) {
            continue;
          }
          {
            int nx = x + a[i];
            if (nx >= p) {
              nx -= p;
            }
            auto &nxt = ndp[j][nx];
            nxt = min(nxt, cur);
          }
          if (j + 1 < k) {
            auto &nxt = ndp[j + 1][a[i]];
            nxt = min(nxt, cur + x);
          }
        }
      }
      swap(dp, ndp);
    }
    int res = inf;
    for (int x = 0; x < p; x++) {
      auto cur = dp[k - 1][x];
      if (cur >= inf) {
        continue;
      }
      res = min(res, cur + x);
    }
    printf("%d\n", res);
    return;
  }
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = (s[i] + a[i]) % p;
  }
  for (int i = 0; i < p; i++) {
    d[i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    int cur = 1;
    for (int x = 0; x <= s[i]; x++) {
      cur = max(cur, d[x] + 1);
    }
    d[s[i]] = cur;
  }
  if (d[s[n]] >= k + 1) {
    printf("%d\n", s[n]);
    return;
  }
  printf("%d\n", s[n] + p);
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