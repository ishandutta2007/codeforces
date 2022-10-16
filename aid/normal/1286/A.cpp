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
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
    if (a[i] == -1) {
      continue;
    }
    a[i] %= 2;
  }
  return true;
}

int dp[maxn][maxn][maxn][2];

void solve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        for (int lst = 0; lst < 2; lst++) {
          dp[i][j][k][lst] = inf;
        }
      }
    }
  }
  dp[0][0][0][0] = 0;
  dp[0][0][0][1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; j + k <= i; k++) {
        for (int lst = 0; lst < 2; lst++) {
          auto cur = dp[i][j][k][lst];
          if (cur >= inf) {
            continue;
          }
          if (a[i] != -1) {
            auto &nxt = dp[i + 1][j + (a[i] ? 0 : 1)][k + (a[i] ? 1 : 0)][a[i]];
            nxt = min(nxt, cur + (lst ^ a[i]));
            continue;
          }
          {
            auto &nxt = dp[i + 1][j + 1][k][0];
            nxt = min(nxt, cur + lst);
          }
          {
            auto &nxt = dp[i + 1][j][k + 1][1];
            nxt = min(nxt, cur + (lst ^ 1));
          }
        }
      }
    }
  }
  printf("%d\n", min(dp[n][(n + 1) / 2][n / 2][0], dp[n][(n + 1) / 2][n / 2][1]));
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