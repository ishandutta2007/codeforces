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
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", c[i]);
  }
  return true;
}

int a[maxn][maxn];
int s[maxn][maxn];

void solve() {
  for (int j = 0; j < m; ++j) {
    s[0][j] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = c[i][j] - '0';
      s[i + 1][j] = s[i][j] + a[i][j];
    }
  }
  int res = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 4; j < n; ++j) {
      int mn = inf;
      for (int k = 0; k < m; ++k) {
        if (k - 3 >= 0) {
          int cur = (j - i - 1) - (s[j][k - 3] - s[i + 1][k - 3]);
          cur += (1 - a[i][k - 2]) + (s[j][k - 2] - s[i + 1][k - 2]) + (1 - a[j][k - 2]);
          cur += (1 - a[i][k - 1]) + (s[j][k - 1] - s[i + 1][k - 1]) + (1 - a[j][k - 1]);
          mn = min(mn, cur);
        }
        {
          int cur = mn + (j - i - 1) - (s[j][k] - s[i + 1][k]);
          res = min(res, cur);
        }
        mn += (1 - a[i][k]) + (s[j][k] - s[i + 1][k]) + (1 - a[j][k]);
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
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}