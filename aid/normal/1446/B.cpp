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
char tmp[maxn];
int n, m;
string a, b;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  scanf("%s", tmp);
  a = tmp;
  scanf("%s", tmp);
  b = tmp;
  return true;
}

int dp[maxn][maxn];

void solve() {
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      auto &cur = dp[i][j];
      cur = 0;
      if (i) {
        cur = max(cur, dp[i - 1][j] - 1);
      }
      if (j) {
        cur = max(cur, dp[i][j - 1] - 1);
      }
      if (i && j && a[i - 1] == b[j - 1]) {
        cur = max(cur, dp[i - 1][j - 1] + 2);
      }
      res = max(res, cur);
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