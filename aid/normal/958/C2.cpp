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

const int maxn = (int) 2e4 + 5, maxk = 55, maxp = 105;
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

int dp[maxk][maxp], ndp[maxk][maxp];

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][a[0]] = 0;
  for (int i = 1; i < n; i++) {
    memset(ndp, -1, sizeof(ndp));
    for (int j = 0; j < k; j++) {
      for (int x = 0; x < p; x++) {
        auto cur = dp[j][x];
        if (cur < 0) {
          continue;
        }
        {
          int nx = x + a[i];
          if (nx >= p) {
            nx -= p;
          }
          auto &nxt = ndp[j][nx];
          nxt = max(nxt, cur);
        }
        if (j + 1 < k) {
          auto &nxt = ndp[j + 1][a[i]];
          nxt = max(nxt, cur + x);
        }
      }
    }
    swap(dp, ndp);
  }
  int res = -1;
  for (int x = 0; x < p; x++) {
    auto cur = dp[k - 1][x];
    if (cur < 0) {
      continue;
    }
    res = max(res, cur + x);
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