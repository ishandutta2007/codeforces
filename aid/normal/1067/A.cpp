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

const int mod = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 1e5 + 5, maxx = 200;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > 0) {
      a[i]--;
    }
  }
  return true;
}

int dp[2][maxx], ndp[2][maxx];

void solve() {
  memset(dp, 0, sizeof(dp));
  if (a[0] == -1) {
    for (int i = 0; i < maxx; i++) {
      dp[0][i] = 1;
    }
  } else {
    dp[0][a[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    memset(ndp, 0, sizeof(ndp));
    int less = 0;
    for (int x = 0; x < maxx; x++) {
      add(ndp[0][x], less);
      int cur = dp[0][x];
      add(cur, dp[1][x]);
      add(ndp[1][x], cur);
      add(less, cur);
    }
    int gr = 0;
    for (int x = maxx - 1; x >= 0; x--) {
      add(ndp[1][x], gr);
      int cur = dp[1][x];
      add(gr, cur);
    }
    if (a[i] != -1) {
      for (int x = 0; x < maxx; x++) {
        if (x != a[i]) {
          ndp[0][x] = 0;
          ndp[1][x] = 0;
        }
      }
    }
    swap(dp, ndp);
  }
  int res = 0;
  for (int i = 0; i < maxx; i++) {
    add(res, dp[1][i]);
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