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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

#define y0 yyyyyyyyyyyy0
#define y1 yyyyyyyyyyyy1

struct Rat {
  long long p, q;

  Rat(): p(0), q(1) {}

  Rat(long long _p, long long _q): p(_p), q(_q) {}

  bool operator < (const Rat &r) const {
    return p * r.q < r.p * q;
  }

  bool operator == (const Rat &r) const {
    return p * r.q == r.p * q;
  }
};

int n;
long long x0, y0, x1, y1;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%lld%lld%lld%lld", &x0, &y0, &x1, &y1);
  return true;
}

void solve1(long long l, long long r, long long x, long long v, Rat &resl, Rat &resr) {
  if (!v) {
    if (l < x && x < r) {
      resl = Rat(0, 1);
      resr = Rat(inf, 1);
      return;
    }
    resl = Rat(0, 1);
    resr = Rat(0, 1);
    return;
  }
  if (v < 0) {
    x *= -1;
    l *= -1;
    r *= -1;
    swap(l, r);
    v *= -1;
  }
  if (x >= r) {
    resl = Rat(0, 1);
    resr = Rat(0, 1);
    return;
  }
  if (x >= l) {
    resl = Rat(0, 1);
    resr = Rat(r - x, v);
    return;
  }
  resl = Rat(l - x, v);
  resr = Rat(r - x, v);
}

void solve() {
  Rat l(0, 1), r(inf, 1);
  for (int i = 0; i < n; i++) {
    long long x, y, vx, vy;
    scanf("%lld%lld%lld%lld", &x, &y, &vx, &vy);
    Rat lx, rx;
    solve1(x0, x1, x, vx, lx, rx);
    Rat ly, ry;
    solve1(y0, y1, y, vy, ly, ry);
    l = max(l, max(lx, ly));
    r = min(r, min(rx, ry));
  }
  if (r < l || r == l) {
    printf("-1\n");
    return;
  }
  printf("%.12f\n", (double) ((ld) l.p / l.q));
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