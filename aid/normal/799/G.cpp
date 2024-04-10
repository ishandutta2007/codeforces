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
  ld x, y;

  point(): x(0), y(0) {}

  point(ld _x, ld _y): x(_x), y(_y) {}
  
  void read() {
    double xx, yy;
    assert(scanf("%lf%lf", &xx, &yy) == 2);
    x = xx;
    y = yy;
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

  point rot(ld alpha) const {
    return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
  }
};

point intersect(const point &a, const point &b, const point &c, const point &d) {
  ld t = ((c - a) ^ d) / (b ^ d);
  return a + b * t;
}

const int maxn = (int) 5e4 + 5;
int n, m;
point ps[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

ld s[maxn];

ld get(const point &a, ld alpha) {
  point b = point(1, 0).rot(alpha);
  bool neg = false;
  if ((b ^ (ps[1] - ps[0])) > 0) {
    b = b * -1;
    neg = true;
  }
  ld x0 = (b ^ (ps[0] - a));
  int l = 0, r = n;
  while (l < r - 1) {
    int m = (l + r) / 2;
    ld cur = (b ^ (ps[m] - a)), nxt = (b ^ (ps[m + 1] - a));
    if (nxt < cur && cur < x0 + 0.5) {
      l = m;
    } else {
      r = m;
    }
  }
  int mn = r;
  l = mn;
  r = l + n;
  while (l < r - 1) {
    int m = (l + r) / 2;
    ld cur = (b ^ (ps[m] - a)), nxt = (b ^ (ps[m + 1] - a));
    if (nxt > cur) {
      l = m;
    } else {
      r = m;
    }
  }
  int mx = r;
  l = mn;
  r = mx;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if ((b ^ (ps[m] - a)) < 0) {
      l = m;
    } else {
      r = m;
    }
  }
  int i0 = l;
  l = mx;
  r = mn + n;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if ((b ^ (ps[m] - a)) > 0) {
      l = m;
    } else {
      r = m;
    }
  }
  int i1 = l;
  ld res = s[i1] - s[i0 + 1];
  point p0 = intersect(ps[i0], ps[i0 + 1] - ps[i0], a, b);
  point p1 = intersect(ps[i1], ps[i1 + 1] - ps[i1], a, b);
  res += (p0 ^ ps[i0 + 1]);
  res += (ps[i1] ^ p1);
  res += (p1 ^ p0);
  res = s[n] - 2 * res;
  if (neg) {
    res *= -1;
  }
  return res;
}

void solve() {
  reverse(ps, ps + n);
  for (int i = 0; i < 5 * n; i++) {
    ps[i] = ps[i % n];
  }
  s[0] = 0;
  for (int i = 0; i + 1 < 5 * n; i++) {
    s[i + 1] = s[i] + (ps[i] ^ ps[i + 1]);
  }
  for (int i = 0; i < m; i++) {
    point q;
    q.read();
    ld l = 0, r = pi;
    bool added = false;
    get(q, l);
    if (get(q, l) > get(q, r)) {
      l += pi;
      r += pi;
      added = true;
    }
    for (int it = 0; it < 50; it++) {
      ld m = (l + r) / 2;
      if (get(q, m) < 0) {
        l = m;
      } else {
        r = m;
      }
    }
    ld res = l;
    if (added) {
      res -= pi;
    }
    res = max((ld) 0, min((ld) 3.14159, res));
    printf("%.12f\n", (double) res);
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