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

  ld operator * (const point &p) const {
    return x * p.x + y * p.y;
  }

  ld slen() const {
    return *this * *this;
  }

  ld len() const {
    return sqrt(slen());
  }

  ld mdist() const {
    return abs(x) + abs(y);
  }
};

int a, b, c;
point p, q;

bool read() {
  if (scanf("%d%d%d", &a, &b, &c) < 3) {
    return false;
  }
  p.read();
  q.read();
  return true;
}

void solve() {
  vector<point> ps;
  if (a) {
    for (int it = 0; it < 2; it++) {
      ld y = (!it ? p.y : q.y);
      ld x = (-c - b * y) / a;
      ps.push_back(point(x, y));
    }
  }
  if (b) {
    for (int it = 0; it < 2; it++) {
      ld x = (!it ? p.x : q.x);
      ld y = (-c - a * x) / b;
      ps.push_back(point(x, y));
    }
  }
  ld res = (q - p).mdist();
  for (int i = 0; i < sz(ps); i++) {
    for (int j = 0; j < sz(ps); j++) {
      res = min(res, (ps[i] - p).mdist() + (ps[j] - ps[i]).len() + (q - ps[j]).mdist());
    }
  }
  printf("%.12f\n", (double) res);
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