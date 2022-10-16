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

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
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

  point norm() const {
    return *this / len();
  }
};

void get(const point &p, const point &v, ld dd, ld &l, ld &r) {
  //eprintf("(%f %f) + (%f %f) * t\n", (double) p.x, (double) p.y, (double) v.x, (double) v.y);
  ld a = (v * v);
  ld b = (p * v);
  ld c = (p * p) - dd * dd;
  if (abs(a) < eps) {
    //assert(abs(b) < eps);
    if (c < eps) {
      l = -inf;
      r = inf;
    } else {
      l = inf;
      r = -inf;
    }
    return;
  }
  ld d = b * b - a * c;
  if (d < -eps) {
    l = inf;
    r = -inf;
    return;
  }
  d = sqrt(max((ld) 0, d));
  l = (-b - d) / a;
  r = (-b + d) / a;
}

const int maxn = (int) 2e5 + 5;
int n, m;
point ps[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

ld x[maxn];
ld len, s;
vector< pair<ld, int> > evs;
int op[maxn];

int getId(ld x) {
  return floor(x / s + eps);
}

void addSeg(ld l, ld r) {
  int idl = getId(l);
  int idr = getId(r);
  while (idl != idr) {
    evs.push_back(make_pair(l - idl * s, idl));
    evs.push_back(make_pair(s, idl));
    l = (idl + 1) * s;
    idl++;
  }
  if (l < r) {
    evs.push_back(make_pair(l - idl * s, idl));
    evs.push_back(make_pair(r - idr * s, idr));
  }
}

bool check(ld d) {
  int pos[2] = {0, 0};
  ld curx[2] = {(ld) 0, (ld) 0};
  {
    ld need = s;
    while (need > eps) {
      ld toadd = min(x[pos[1] + 1] - curx[1], need);
      need -= toadd;
      curx[1] += toadd;
      if (curx[1] > x[pos[1] + 1] - eps) {
        pos[1]++;
      }
    }
  }
  evs.clear();
  while (pos[0] < n) {
    /*for (int i = 0; i < 2; i++) {
      eprintf("(%d %f) ", pos[i], (double) curx[i]);
    }
    eprintf("\n");*/
    ld toadd = min(x[pos[0] + 1] - curx[0], x[pos[1] + 1] - curx[1]);
    point p[2];
    point v[2];
    for (int i = 0; i < 2; i++) {
      v[i] = (ps[pos[i] + 1] - ps[pos[i]]).norm();
      p[i] = ps[pos[i]] + v[i] * (curx[i] - x[pos[i]]);
    }
    ld l, r;
    get(p[1] - p[0], v[1] - v[0], d, l, r);
    l += curx[0];
    r += curx[0];
    l = max(l, curx[0]);
    r = min(r, curx[0] + toadd);
    if (l < r) {
      addSeg(l, r);
    }
    for (int i = 0; i < 2; i++) {
      curx[i] += toadd;
      if (curx[i] > x[pos[i] + 1] - eps) {
        pos[i]++;
      }
    }
  }
  sort(evs.begin(), evs.end());
  int ok = 0;
  for (int i = 0; i < m; i++) {
    op[i] = 0;
  }
  for (int i = 0; i < sz(evs); i++) {
    int id = evs[i].second;
    ok -= op[id];
    op[id] ^= 1;
    ok += op[id];
    if (ok == m) {
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < n; i++) {
    ps[n + i] = ps[i];
  }
  len = 0;
  x[0] = len;
  for (int i = 0; i < n; i++) {
    len += (ps[i + 1] - ps[i]).len();
    x[i + 1] = len;
  }
  for (int i = 0; i < n; i++) {
    x[n + i] = x[i] + len;
  }
  s = len / m;
  ld l = 0, r = 1e4;
  for (int it = 0; it < 50; it++) {
    ld mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.12f\n", (double) l);
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