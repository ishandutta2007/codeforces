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

const int maxn = 155, maxs = maxn * maxn;
int n, k, s;
int a[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &k, &s) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int dp[maxn][maxs], ndp[maxn][maxs];

void solve() {
  s = min(s, k * (n - k));
  for (int i = 0; i <= s; i++) {
    dp[0][i] = inf;
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i + 1; j++) {
      for (int t = 0; t <= s; t++) {
        ndp[j][t] = inf;
      }
    }
    for (int j = 0; j <= i; j++) {
      for (int t = 0; t <= s; t++) {
        auto cur = dp[j][t];
        if (cur >= inf) {
          continue;
        }
        ndp[j][t] = min(ndp[j][t], cur);
        int nt = t + (i - j);
        if (nt <= s) {
          ndp[j + 1][nt] = min(ndp[j + 1][nt], cur + a[i]);
        }
      }
    }
    swap(dp, ndp);
  }
  int res = inf;
  for (int t = 0; t <= s; t++) {
    res = min(res, dp[k][t]);
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