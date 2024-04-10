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

const int maxn = 85;
int n, k;
int g[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  return true;
}

int c[maxn];
int dp[maxn], ndp[maxn];
int res;

void solve() {
  res = inf;
  while ((double) clock() / CLOCKS_PER_SEC < 2.8) {
    c[0] = 0;
    for (int i = 1; i < n; i++) {
      c[i] = rnd(2);
    }
    for (int i = 0; i < n; i++) {
      dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
      for (int i = 0; i < n; i++) {
        ndp[i] = inf;
      }
      for (int v = 0; v < n; v++) {
        if (dp[v] >= inf || c[v] != (i & 1)) {
          continue;
        }
        for (int u = 0; u < n; u++) {
          if (c[u] == c[v]) {
            continue;
          }
          ndp[u] = min(ndp[u], dp[v] + g[v][u]);
        }
      }
      swap(dp, ndp);
    }
    res = min(res, dp[0]);
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