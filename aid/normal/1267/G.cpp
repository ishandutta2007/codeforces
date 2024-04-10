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

const int maxn = 105, maxx = (int) 1e4 + 5;
ld cc[maxn][maxn];

void precalc() {
  for (int i = 0; i < maxn; i++) {
    cc[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      cc[i][j] = cc[i - 1][j - 1] + cc[i - 1][j];
    }
  }
}

int n, x;
int c[maxn];

bool read() {
  if (scanf("%d%d", &n, &x) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  return true;
}

ld dp[maxn][maxx];

void solve() {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += c[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][s] = 1;
  for (int i = 0; i < n; i++) {
    for (int k = i; k >= 0; k--) {
      for (int x = 0; x <= s; x++) {
        auto cur = dp[k][x];
        if (cur < eps) {
          continue;
        }
        dp[k + 1][x - c[i]] += cur;
      }
    }
  }
  ld res = 0;
  for (int k = 0; k < n; k++) {
    ld val = x + (ld) k / (n - k) * x / 2.;
    for (int x = 0; x <= s; x++) {
      auto cur = dp[k][x];
      if (cur < eps) {
        continue;
      }
      cur /= cc[n][k];
      res += cur * min((ld) x / (n - k), val);
    }
  }
  printf("%.12f\n", (double) res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  /*for (int tt = 0; tt < 1000; tt++) {
    n = rnd(5) + 1;
    x = rnd(10) + 1;
    for (int i = 0; i < n; i++) {
      c[i] = x + rnd(10);
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }*/
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}