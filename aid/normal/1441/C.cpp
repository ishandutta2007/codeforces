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

const int maxn = 3005;
int n, k;
vector<vector<long long>> a;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  a.clear();
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    int m;
    scanf("%d", &m);
    a[i].resize(m + 1);
    a[i][0] = 0;
    for (int j = 0; j < m; ++j) {
      int x;
      scanf("%d", &x);
      a[i][j + 1] = a[i][j] + x;
    }
  }
  return true;
}

const int logn = 20;
long long dp[logn][maxn];
long long res;

void rec(int d, int l, int r) {
  if (l == r - 1) {
    for (int i = 0; i <= k; ++i) {
      if (dp[d][i] >= 0 && k - i < sz(a[l])) {
        res = max(res, dp[d][i] + a[l][k - i]);
      }
    }
    return;
  }
  int m = (l + r) / 2;
  for (int i = k; i >= 0; --i) {
    dp[d + 1][i] = dp[d][i];
  }
  for (int it = m; it < r; ++it) {
    int x = sz(a[it]) - 1;
    long long val = a[it].back();
    for (int i = k - x; i >= 0; --i) {
      auto cur = dp[d + 1][i];
      if (cur >= 0) {
        dp[d + 1][i + x] = max(dp[d + 1][i + x], cur + val);
      }
    }
  }
  rec(d + 1, l, m);
  for (int i = k; i >= 0; --i) {
    dp[d + 1][i] = dp[d][i];
  }
  for (int it = l; it < m; ++it) {
    int x = sz(a[it]) - 1;
    long long val = a[it].back();
    for (int i = k - x; i >= 0; --i) {
      auto cur = dp[d + 1][i];
      if (cur >= 0) {
        dp[d + 1][i + x] = max(dp[d + 1][i + x], cur + val);
      }
    }
  }
  rec(d + 1, m, r);
}

void solve() {
  for (int i = 0; i <= k; ++i) {
    dp[0][i] = -infll;
  }
  res = -infll;
  dp[0][0] = 0;
  rec(0, 0, n);
  printf("%lld\n", res);
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