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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 105, maxx = maxn * maxn;
int n;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  return true;
}

int dp[maxn][maxx], ndp[maxn][maxx];

void solve() {
  for (int k = 0; k <= n; ++k) {
    for (int i = 0; i < maxx; ++i) {
      dp[k][i] = -inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k <= n; ++k) {
      for (int x = 0; x < maxx; ++x) {
        ndp[k][x] = -inf;
      }
    }
    for (int k = 0; k <= i; ++k) {
      for (int x = 0; x < maxx; ++x) {
        auto cur = dp[k][x];
        if (cur < 0) {
          continue;
        }
        {
          auto val = cur + 2 * b[i];
          if (val > ndp[k + 1][x + a[i]]) {
            ndp[k + 1][x + a[i]] = val;
          }
        }
        {
          auto val = cur + b[i];
          if (val > ndp[k][x]) {
            ndp[k][x] = val;
          }
        }
      }
    }
    swap(dp, ndp);
  }
  for (int k = 1; k <= n; ++k) {
    int cur = -inf;
    for (int x = 0; x < maxx; ++x) {
      cur = max(cur, min(2 * x, dp[k][x]));
    }
    printf("%.12f ", (double) cur / 2);
  }
  printf("\n");
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