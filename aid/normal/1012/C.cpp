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

const int maxn = 5005;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int dp[maxn], ndp[maxn];
int dp1[maxn];

void solve() {
  int res = inf;
  for (int i = 0; i < n; i++) {
    auto &cur = dp[i];
    cur = 0;
    if (i) {
      cur += max(a[i - 1] - a[i] + 1, 0);
    }
    if (i + 1 < n) {
      cur += max(a[i + 1] - a[i] + 1, 0);
    }
    res = min(res, cur);
  }
  for (int i = 0; i < n; i++) {
    dp1[i] = dp[i];
  }
  printf("%d ", res);
  for (int k = 2; k <= (n + 1) / 2; k++) {
    res = inf;
    int mn = inf;
    for (int i = 0; i < n; i++) {
      auto &cur = ndp[i];
      cur = inf;
      cur = min(cur, mn + dp1[i]);
      if (i >= 2) {
        auto val = dp[i - 2];
        int x = max(a[i - 1] - a[i - 2] + 1, 0);
        val -= x;
        x = max(a[i - 1] - min(a[i - 2], a[i]) + 1, 0);
        val += x;
        if (i + 1 < n) {
          val += max(a[i + 1] - a[i] + 1, 0);
        }
        cur = min(cur, val);
        mn = min(mn, dp[i - 2]);
      }
      res = min(res, cur);
    }
    swap(dp, ndp);
    printf("%d ", res);
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