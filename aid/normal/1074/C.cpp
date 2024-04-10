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

struct point {
  int x, y;

  point(): x(0), y(0) {}

  point(int _x, int _y): x(_x), y(_y) {}

  bool read() {
    return (scanf("%d%d", &x, &y) == 2);
  }
};

const int maxn = (int) 3e5 + 5;
int n;
point ps[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

void solve() {
  int x0 = inf, y0 = inf, x1 = -inf, y1 = -inf;
  for (int i = 0; i < n; i++) {
    x0 = min(x0, ps[i].x);
    y0 = min(y0, ps[i].y);
    x1 = max(x1, ps[i].x);
    y1 = max(y1, ps[i].y);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, (ps[i].x - x0) + (ps[i].y - y0));
    res = max(res, (ps[i].x - x0) + (y1 - ps[i].y));
    res = max(res, (x1 - ps[i].x) + (ps[i].y - y0));
    res = max(res, (x1 - ps[i].x) + (y1 - ps[i].y));
  }
  res *= 2;
  printf("%d ", res);
  for (int i = 4; i <= n; i++) {
    printf("%d ", 2 * ((x1 - x0) + (y1 - y0)));
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