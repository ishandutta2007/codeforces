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
  long long x, y;

  point(): x(0), y(0) {}

  point(long long xx, long long yy): x(xx), y(yy) {}

  bool read() {
    return scanf("%lld%lld", &x, &y) == 2;
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  long long operator ^ (const point &p) const {
    return x * p.y - y * p.x;
  }

  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }

  bool operator == (const point &p) const {
    return x == p.x && y == p.y;
  }
};

const int maxn = (int) 1e6 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<point> ps;

void solve() {
  ps.clear();
  ps.push_back(point(1, a[0]));
  for (int i = 1; i < n; i++) {
    point q(1, a[i]);
    while (!ps.empty() && (ps.back() ^ q) <= 0) {
      q = q + ps.back();
      ps.pop_back();
    }
    ps.push_back(q);
  }
  for (int i = 0; i < sz(ps); i++) {
    for (int j = 0; j < ps[i].x; j++) {
      printf("%.12f\n", (double) ps[i].y / ps[i].x);
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