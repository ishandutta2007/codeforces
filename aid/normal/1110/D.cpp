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

const int maxn = (int) 1e6 + 5;
int n, m;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x--;
    a[x]++;
  }
  return true;
}

int dp[maxn][3][3];

void solve() {
  a[m] = 0;
  a[m + 1] = 0;
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int x = 0; x < m; x++) {
    for (int c0 = 0; c0 < 3; c0++) {
      for (int c1 = 0; c1 < 3; c1++) {
        auto cur = dp[x][c0][c1];
        if (cur == -1) {
          continue;
        }
        int can = min(min(a[x] - c0 - c1, a[x + 1] - c1), min(a[x + 2], 2));
        for (int take = 0; take <= can; take++) {
          auto &nxt = dp[x + 1][c1][take];
          nxt = max(nxt, cur + take + (a[x] - c0 - c1 - take) / 3);
        }
      }
    }
  }
  printf("%d\n", dp[m][0][0]);
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