#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

  bool operator == (const point &p) const {
    return abs(x - p.x) < eps && abs(y - p.y) < eps;
  }

  int type() const {
    return x < -eps || (x < eps && y < -eps);
  }

  char *str() const {
    char *s = new char[100];
    sprintf(s, "(%.12f %.12f)", (double) x, (double) y);
    return s;
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  ld cp = (a ^ b);
  if (abs(cp) > eps) {
    return cp > 0;
  }
  return a.slen() < b.slen();
}

ld getAlpha(const point &a, const point &b) {
  return atan2(a ^ b, a * b);
}

bool onSeg(const point &p, const point &a, const point &b) {
  if (a == b) {
    return p == a;
  }
  return abs((b - a) ^ (p - a)) < eps && ((b - a) * (p - a)) > -eps && ((a - b) * (p - b)) > -eps;
}

bool inside(const point &a, const vector<point> &ps) {
  for (int i = 0; i + 1 < sz(ps); i++) {
    if (onSeg(a, ps[i], ps[i + 1])) {
      return true;
    }
  }
  ld alpha = 0;
  for (int i = 0; i + 1 < sz(ps); i++) {
    alpha += getAlpha(ps[i] - a, ps[i + 1] - a);
  }
  return alpha > 1;
}

bool intersect(const point &a, const point &b, const point &c, const point &d, ld &t) {
  ld det = ((b - a) ^ (d - c));
  if (abs(det) < eps) {
    return false;
  }
  t = ((c - a) ^ (d - c)) / det;
  point p = a + (b - a) * t;
  if (((d - c) * (p - c)) < -eps || ((c - d) * (p - d)) < -eps) {
    return false;
  }
  return true;
}

bool intersect(const point &a, const point &b, const vector<point> &ps, point &pl, point &pr) {
  ld l = inf, r = -inf;
  for (int i = 0; i + 1 < sz(ps); i++) {
    if (onSeg(ps[i], a, b)) {
      ld t = (ps[i].x - a.x) / (b.x - a.x);
      l = min(l, t);
      r = max(r, t);
    }
    if (ps[i] == ps[i + 1]) {
      continue;
    }
    ld t;
    if (intersect(a, b, ps[i], ps[i + 1], t)) {
      l = min(l, t);
      r = max(r, t);
    }
  }
  l = max(l, (ld) 0);
  r = min(r, (ld) 1);
  if (l > r + eps) {
    return false;
  }
  pl = a + (b - a) * l;
  pr = a + (b - a) * r;
  return true;
}

const int maxn = (int) 1e5 + 5;
int w, h;
point p0;
vector<point> qs[maxn];

int read() {
  int n;
  if (scanf("%d%d%d", &n, &w, &h) < 3) {
    return false;
  }
  p0.read();
  for (int i = 0; i < maxn; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    qs[t].push_back(point(x, y));
  }
  return true;
}

pair<point, point> segs[maxn];

bool check(ld v) {
  pair<point, point> cur = make_pair(p0, p0);
  int lst = 0;
  for (int i = 0; i < maxn; i++) {
    if (qs[i].empty()) {
      continue;
    }
    ld d = (i - lst) * v;
    vector<point> ps;
    {
      vector<point> a = {cur.second - cur.first, cur.first - cur.second};
      vector<point> b = {point(2 * d, 0), point(0, 2 * d), point(-2 * d, 0), point(0, -2 * d)};
      vector<point> es(sz(a) + sz(b));
      merge(a.begin(), a.end(), b.begin(), b.end(), es.begin());
      ps.push_back(cur.first + point(-d, -d));
      for (int j = 0; j < sz(es); j++) {
        point nxt = ps.back() + es[j];
        ps.push_back(nxt);
      }
    }
    point a = segs[i].first, b = segs[i].second;
    if (a == b) {
      if (inside(a, ps)) {
        cur = make_pair(a, a);
      } else {
        return false;
      }
    } else {
      if (!intersect(a, b, ps, cur.first, cur.second)) {
        return false;
      }
    }
    lst = i;
  }
  return true;
}

void solve() {
  for (int i = 0; i < maxn; i++) {
    const auto &v = qs[i];
    if (v.empty()) {
      continue;
    }
    point p, q(-1, -1);
    p = v[0];
    bool bad = false;
    for (int j = 1; j < sz(v); j++) {
      if (v[j] == p) {
        continue;
      }
      if (q.x < -0.5) {
        q = v[j];
        continue;
      }
      if (abs((q - p) ^ (v[j] - p)) > 0.5) {
        bad = true;
        break;
      }
    }
    if (bad) {
      printf("-1\n");
      return;
    }
    if (q.x < -0.5) {
      point a(0, p.x * h / p.y);
      point b(w, w + (p.x - w) * h / p.y);
      if (a.y > w) {
        a = a + (b - a) * ((w - a.y) / (b.y - a.y));
      }
      if (b.y < 0) {
        b = b + (a - b) * (-b.y / (a.y - b.y));
      }
      segs[i] = make_pair(a, b);
    } else {
      if (abs(q.y - p.y) < eps) {
        printf("-1\n");
        return;
      }
      if (q.y < p.y) {
        swap(p, q);
      }
      ld x = p.x * (q.y - p.y) - p.y * (q.x - p.x);
      ld y = x + h * (q.x - p.x);
      if (x < -0.5 || x > w * (q.y - p.y) + 0.5 || y < -0.5 || y > w * (q.y - p.y) + 0.5) {
        printf("-1\n");
        return;
      }
      point a(x / (q.y - p.y), y / (q.y - p.y));
      segs[i] = make_pair(a, a);
    }
  }
  ld l = 0, r = w;
  for (int it = 0; it < 50; it++) {
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