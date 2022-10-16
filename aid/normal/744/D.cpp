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

  point ort() const {
    return point(-y, x);
  }

  point inv() const {
    return *this / slen();
  }

  bool operator < (const point &p) const {
    return x < p.x - eps || (x < p.x + eps && y < p.y - eps);
  }
};

struct angleComp {
  bool operator () (const point &a, const point &b) const {
    ld cp = (a ^ b);
    if (abs(cp) > eps) {
      return cp > 0;
    }
    return a.slen() < b.slen() - eps;
  }
};

ld getAngle(const point &a, const point &b) {
  return atan2(a ^ b, a * b);
}

bool onSeg(const point &p, const point &a, const point &b) {
  return abs((p - a) ^ (b - a)) < eps && ((p - a) * (b - a)) > -eps && ((p - b) * (a - b)) > -eps;
}

point intersect(const point &a, const point &b, const point &c, const point &d) {
  ld t = ((c - a) ^ (d - c)) / ((b - a) ^ (d - c));
  return a + (b - a) * t;
}

vector<point> intersect(const vector<point> &p, const point &o, const point &dir) {
  vector<point> res;
  bool inside = (dir ^ (p[0] - o)) > eps;
  if (inside) {
    res.push_back(p[0]);
  }
  for (int i = 0; i + 1 < sz(p); i++) {
    bool ninside = (dir ^ (p[i + 1] - o)) > eps;
    if (ninside != inside) {
      res.push_back(intersect(o, o + dir, p[i], p[i + 1]));
    }
    inside = ninside;
    if (inside) {
      res.push_back(p[i + 1]);
    }
  }
  if (!inside) {
    res.push_back(res[0]);
  }
  return res;
}

const int maxn = 1005;
int n, m;
point a[maxn], b[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    a[i].read();
  }
  for (int i = 0; i < m; i++) {
    b[i].read();
  }
  return true;
}

point ps[maxn];

int buildCH(int n) {
  for (int i = 1; i < n; i++) {
    if (ps[i] < ps[0]) {
      swap(ps[i], ps[0]);
    }
  }
  for (int i = 1; i < n; i++) {
    ps[i] = ps[i] - ps[0];
  }
  sort(ps + 1, ps + n, angleComp());
  for (int i = 1; i < n; i++) {
    ps[i] = ps[i] + ps[0];
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k >= 2 && ((ps[k - 1] - ps[k - 2]) ^ (ps[i] - ps[k - 1])) <= eps) {
      k--;
    }
    ps[k++] = ps[i];
  }
  ps[k] = ps[0];
  return k;
}

bool inside(int n, const point &p) {
  for (int i = 0; i < n; i++) {
    if (onSeg(p, ps[i], ps[i + 1])) {
      return false;
    }
  }
  ld alpha = 0;
  for (int i = 0; i < n; i++) {
    alpha += getAngle((ps[i] - p), (ps[i + 1] - p));
  }
  return abs(alpha) > 1;
}

void solve() {
  {
    for (int i = 0; i < m; i++) {
      ps[i] = b[i];
    }
    int k = buildCH(m);
    for (int i = 0; i < n; i++) {
      if (!inside(k, a[i])) {
        printf("-1\n");
        return;
      }
    }
  }
  ld res = 0;
  for (int i = 0; i < m; i++) {
    vector<point> p = {{-inf, -inf}, {inf, -inf}, {inf, inf}, {-inf, inf}, {-inf, -inf}};
    for (int j = 0; j < m; j++) {
      if (j != i) {
        p = intersect(p, (b[i] + b[j]) / 2, (b[j] - b[i]).ort());
      }
    }
    for (int j = 0; j + 1 < sz(p); j++) {
      point o = p[j];
      ld r = (b[i] - o).len();
      if (r < res) {
        continue;
      }
      bool ok = false;
      for (int k = 0; k < n; k++) {
        if ((a[k] - o).len() < r + eps) {
          ok = true;
          break;
        }
      }
      if (ok) {
        res = max(res, r);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ps[j] = (b[j] - a[i]).inv() * 10000;
    }
    int k = buildCH(m);
    for (int j = 0; j < k; j++) {
      ld r = ((ps[j + 1] - ps[j]) ^ (point() - ps[j])) / (ps[j + 1] - ps[j]).len();
      res = max(res, 10000. / r / 2.);
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