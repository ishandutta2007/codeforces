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

const int maxn = 405;
int n, mod;

bool read() {
  if (scanf("%d%d", &n, &mod) < 2) {
    return false;
  }
  return true;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int dp[maxn][maxn][2];
int ndp[maxn][maxn][2];

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[1][0][1] = 1;
  for (int i = 1; i < n; ++i) {
    for (int k = 0; k <= i; ++k) {
      for (int t = 0; t < 2; ++t) {
        int s = 0;
        for (int j = 0; j <= k + 1; ++j) {
          auto cur = dp[k][j][t];
          dp[k][j][t] = s;
          add(s, cur);
        }
      }
    }
    memset(ndp, 0, sizeof(ndp));
    for (int k = 1; k <= i + 1; ++k) {
      for (int j = 0; j < k; ++j) {
        {
          auto &cur = ndp[k][j][0];
          cur = dp[k - 1][j][0];
          add(cur, dp[k - 1][j][1]);
        }
        {
          auto &cur = ndp[k][j][1];
          cur = dp[k - 1][k][1];
          add(cur, mod - dp[k - 1][j][1]);
        }
      }
      {
        auto &cur = ndp[k][k][1];
        cur = dp[k][k][0];
        add(cur, dp[k][k][1]);
      }
    }
    swap(dp, ndp);
  }
  int res = 0;
  for (int k = 1; k <= n; ++k) {
    for (int j = 0; j < k; ++j) {
      for (int t = 0; t < 2; ++t) {
        add(res, dp[k][j][t]);
      }
    }
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