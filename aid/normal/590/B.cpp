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

struct point {
  ld x, y;

  point(): x(0), y(0) {}

  point(ld _x, ld _y): x(_x), y(_y) {}

  bool read() {
    double xx, yy;
    if (scanf("%lf%lf", &xx, &yy) < 2) {
      return false;
    }
    x = xx;
    y = yy;
    return true;
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  point operator * (ld k) const {
    return point(x * k, y * k);
  }

  point operator / (ld k) const {
    return point(x / k, y / k);
  }

  ld operator ^ (const point &p) const {
    return x * p.y - y * p.x;
  }
  
  ld operator * (const point &p) const {
    return x * p.x + y * p.y;
  }

  ld slen() const {
    return *this * *this;
  }

  ld len() const {
    return sqrt(slen());
  }
};

point p, q;
int vmax, t;
point v0, v1;

bool read() {
  if (!p.read()) {
    return false;
  }
  if (!q.read()) {
    return false;
  }
  scanf("%d%d", &vmax, &t);
  v0.read();
  v1.read();
  return true;
}

bool check(ld x) {
  ld x0 = min(x, (ld) t);
  ld x1 = x - x0;
  point a = q + v0 * x0 + v1 * x1;
  return (a - p).len() / (ld) vmax <= x;
}

void solve() {
  v0 = v0 * -1;
  v1 = v1 * -1;
  ld l = 0, r = inf;
  for (int it = 0; it < 200; it++) {
    ld m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%.12f\n", (double) r);
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