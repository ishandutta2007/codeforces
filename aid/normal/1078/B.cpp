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

const int maxn = 105;
int n;
int cnt[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < maxn; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  return true;
}

const int maxx = maxn * maxn;
int dp[maxn][maxx], ndp[maxn][maxx];

void upd(int &x, int y) {
  x += y;
  x = min(x, 2);
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int x = 0; x < maxn; x++) {
    if (!cnt[x]) {
      continue;
    }
    memset(ndp, 0, sizeof(ndp));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < maxx; j++) {
        auto cur = dp[i][j];
        if (!cur) {
          continue;
        }
        for (int k = 0; k <= cnt[x]; k++) {
          upd(ndp[i + k][j + k * x], cur);
        }
      }
    }
    swap(dp, ndp);
  }
  int l = 0;
  for (int i = 0; i < maxn; i++) {
    if (cnt[i]) {
      l++;
    }
  }
  int res = 0;
  for (int s = 0; s < maxn; s++) {
    if (!cnt[s]) {
      continue;
    }
    for (int k = 1; k <= cnt[s]; k++) {
      if (dp[k][k * s] <= 1) {
        res = max(res, k);
        if (k == cnt[s] && l <= 2) {
          res = n;
        }
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