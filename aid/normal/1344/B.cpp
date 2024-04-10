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

const int maxn = 1005;
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

bool intersect(int a, int b, int c, int d) {
  if (a == inf || c == inf) {
    return false;
  }
  return max(a, c) <= min(b, d);
}

void solve() {
  bool erow = false;
  int res = 0;
  int pl = inf, pr = -1;
  for (int i = 0; i < n; i++) {
    int l = inf, r = -1;
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '#') {
        l = min(l, j);
        r = max(r, j);
      }
    }
    if (l == inf) {
      erow = true;
    } else {
      if (!intersect(pl, pr, l, r)) {
        res++;
      }
      for (int j = l; j <= r; j++) {
        if (c[i][j] != '#') {
          printf("-1\n");
          return;
        }
      }
    }
    pl = l;
    pr = r;
  }
  bool ecol = false;
  for (int j = 0; j < m; j++) {
    int l = inf, r = -1;
    for (int i = 0; i < n; i++) {
      if (c[i][j] == '#') {
        l = min(l, i);
        r = max(r, i);
      }
    }
    if (l == inf) {
      ecol = true;
    } else {
      for (int i = l; i <= r; i++) {
        if (c[i][j] != '#') {
          printf("-1\n");
          return;
        }
      }
    }
  }
  if (erow != ecol) {
    printf("-1\n");
    return;
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