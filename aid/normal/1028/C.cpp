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

const int maxn = (int) 2e5 + 5;
int n;
int ps[maxn][2][2];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        scanf("%d", &ps[i][j][k]);
      }
    }
  }
  return true;
}

int pref[maxn][2][2], suff[maxn][2][2];

void solve() {
  pref[0][0][0] = -inf;
  pref[0][0][1] = -inf;
  pref[0][1][0] = inf;
  pref[0][1][1] = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (!j) {
          pref[i + 1][j][k] = max(pref[i][j][k], ps[i][j][k]);
        } else {
          pref[i + 1][j][k] = min(pref[i][j][k], ps[i][j][k]);
        }
      }
    }
  }
  suff[n][0][0] = -inf;
  suff[n][0][1] = -inf;
  suff[n][1][0] = inf;
  suff[n][1][1] = inf;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (!j) {
          suff[i][j][k] = max(suff[i + 1][j][k], ps[i][j][k]);
        } else {
          suff[i][j][k] = min(suff[i + 1][j][k], ps[i][j][k]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int cur[2][2];
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (!j) {
          cur[j][k] = max(pref[i][j][k], suff[i + 1][j][k]);
        } else {
          cur[j][k] = min(pref[i][j][k], suff[i + 1][j][k]);
        }
      }
    }
    if (cur[0][0] <= cur[1][0] && cur[0][1] <= cur[1][1]) {
      printf("%d %d\n", cur[0][0], cur[0][1]);
      return;
    }
  }
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