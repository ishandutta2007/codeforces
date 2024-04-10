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
    int xx, yy;
    assert(scanf("%d%d", &xx, &yy) == 2);
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

  point norm() const {
    return *this / len();
  }

  point ort() const {
    return point(-y, x);
  }

  bool operator < (const point &p) const {
    return x < p.x - eps || (x < p.x + eps && y < p.y - eps);
  }
};

bool intersect(point o0, ld r0, point o1, ld r1, point ans[2]) {
  if (r0 < r1) {
    swap(o0, o1);
    swap(r0, r1);
  }
  ld d = (o1 - o0).len();
  if (d > r0 + r1 + eps || d < r0 - r1 - eps || d < eps) {
    return false;
  }
  ld cosa = (r0 * r0 + d * d - r1 * r1) / (2 * r0 * d);
  ld sina = sqrt(max((ld) 0, 1 - cosa * cosa));
  point v = (o1 - o0).norm() * r0;
  point u = v.ort();
  v = v * cosa;
  u = u * sina;
  for (int i = 0; i < 2; i++) {
    ans[i] = o0 + v + u * (!i ? -1 : 1);
  }
  return true;
}

const int maxn = 5;
int n;
point ps[maxn];
int rs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
    scanf("%d", &rs[i]);
  }
  return true;
}

int bad[maxn];
set<point> vs;

void solve() {
  vs.clear();
  int res = 1;
  for (int i = 0; i < n; i++) {
    bad[i] = true;
    for (int j = 0; j < n; j++) {
      point qs[2];
      if (intersect(ps[i], rs[i], ps[j], rs[j], qs)) {
        bad[i] = false;
        vs.insert(qs[0]);
        vs.insert(qs[1]);
      }
    }
    if (bad[i]) {
      res++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!bad[i]) {
      res++;
      break;
    }
  }
  res -= sz(vs);
  for (int i = 0; i < n; i++) {
    for (auto it = vs.begin(); it != vs.end(); it++) {
      if (abs((*it - ps[i]).len() - rs[i]) < eps) {
        res++;
      }
    }
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