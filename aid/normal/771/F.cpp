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

//BEGIN ALGO
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

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  ld operator * (const point &p) const {
    return x * p.x + y * p.y;
  }

  ld operator ^ (const point &p) const {
    return x * p.y - y * p.x;
  }

  point operator * (const ld &k) const {
    return point(x * k, y * k);
  }
  
  point operator / (const ld &k) const {
    return point(x / k, y / k);
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

  bool operator == (const point &p) const {
    return abs(x - p.x) < eps && abs(y - p.y) < eps;
  }

  int type() const {
    return y < -eps || (y <= eps && x < -eps);
  }

  const char *str() const {
    char *ans = new char[100];
    sprintf(ans, "(%.3f, %.3f)", (double) x, (double) y);
    return ans;
  }
};

struct angleComp {
  bool operator () (const point &a, const point &b) const {
    int at = a.type(), bt = b.type();
    if (at != bt) {
      return at < bt;
    }
    ld cp = (a ^ b);
    if (abs(cp) > eps) {
      return cp > 0;
    }
    return a.slen() < b.slen() - eps;
  }
};

struct line {
  point p, v;

  // p + v * alf

  line() {}
  line(const point &p_, const point &v_) : p(p_), v(v_) {}

  ld get(const point &x) const {
    return v ^ (x - p);
  }

  // half: get > 0

  bool operator < (const line &l) const {
    if (v.type() != l.v.type()) {
      return v.type() < l.v.type();
    }
    return (v ^ l.v) > (ld) 0.5;
  }
};

//intersect two lines, assume they do not coincide
bool intersect(const line &a, const line &b, point &res) { 
  ld d = (a.v ^ b.v);
  if (abs(d) < 0.5) { // eps!!!
    return false;
  }
  res = a.p + a.v * (((b.p - a.p) ^ b.v) / d);
#ifdef DEBUG
  assert(abs(a.get(res)) < 1e-3 && abs(b.get(res)) < 1e-3);
#endif
  return true;
}


//a, b, c are on the same line, check if c is in [a,b]
bool inside(point a, point b, point c) {
  if (b < a) {
    swap(a, b);
  }
  return !(c < a || b < c);
}

//intersect [a,b] and [c,d]
//assume they are not on the same line and have positive length
bool intersect(point a, point b, point c, point d, point &res) {
  if (!intersect(line(a, b), line(c, d), res)) {
    return false;
  }
  return inside(a, b, res) && inside(c, d, res);
}

//intersect line and circle
bool intersect(line l, point o, ld r, point res[2]) {
  point u = l.v.norm();
  point v = u.ort();
  ld d = (l.p - o) * v;
  if (abs(d) > r + eps) {
    return false;
  }

  ld x = sqrt(max((ld) 0, r * r - d * d));

  for (int it = 0; it < 2; ++it) {
    res[it] = o + v * d + u * (it ? -x : x);
  }
  return true;
}

//intersect two circles
bool intersect(point o1, ld r1, point o2, ld r2, point res[2]) {
  if (r1 < r2 - eps) {
    swap(o1, o2);
    swap(r1, r2);
  }
  ld d = (o2 - o1).len();
  if (r1 + r2 < d - eps || r1 - r2 > d + eps) {
    return false;
  }

  ld cosa = (r1 * r1 + d * d - r2 * r2) / ((ld) 2 * r1 * d);
  ld sina = sqrt(max((ld) 0, (ld) 1 - cosa * cosa));
  point v1 = (o2 - o1).norm() * r1;
  point v2 = v1.ort();

  for (int it = 0; it < 2; ++it) {
    res[it] = o1 + v1 * cosa + v2 * (it ? -sina : sina); 
  }
  return true;
}

int commonTangents(point o1, ld r1, point o2, ld r2, point *res) {
  ld d = (o1 - o2).len();
  if (d < eps) {
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < 2; ++i) {
    ld cosa = (r1 + (i ? -r2 : r2)) / d;
    if (abs(cosa) < (ld) 1 + eps) {
      ld sina = sqrt(max((ld) 0, (ld) 1 - cosa * cosa));
      point v1 = (o2 - o1).norm() * r1;
      point v2 = v1.ort();
      for (int it = 0; it < 2; ++it) {
        res[cnt++] = o1 + v1 * cosa + v2 * (it ? -sina : sina);
      }
    }
  }
  return cnt;
}

namespace Halfplane {
  const static int maxn = (int) 4e5 + 10;
  line ls[maxn];
  int st[maxn * 2];
  point p[maxn];

  int intersect(int n, line *_ls, point *res) {
    for (int i = 0; i < n; ++i) {
      ls[i] = _ls[i];
    }

    const int inf = (int) 1e6;
    static point box[4] = {
      point(inf, -inf),
      point(inf, inf),
      point(-inf, inf),
      point(-inf, -inf)
    };
    for (int i = 0; i < 4; ++i) {
      ls[n++] = line(box[i], box[(i + 1) % 4] - box[i]);
    }

    sort(ls, ls + n);

    int n0 = n;
    n = 0;
    for (int iter = 0; iter < 2; ++iter) {
      for (int i = 0; i < n0; ++i) {
        bool fail = 0;
        while (n) {
          int p = st[n - 1];
          if (abs(ls[i].v ^ ls[p].v) < 0.5) {
            if (ls[i].v.type() != ls[p].v.type()) {
              return -1;
            }
            if (ls[p].get(ls[i].p) <= eps) {
              fail = 1;
              break;
            }
            --n;
            continue;
          }

          if (n > 1) {
            point q;
            assert(intersect(ls[i], ls[p], q));
            int pp = st[n - 2];
            if (ls[pp].get(q) < -eps) {
              --n;
              continue;
            }
          }
          break;
        }
        if (!fail) {
          st[n++] = i;
        }
      }
    }

    vector<int> when(n0, -1);
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
      auto &cur = when[st[i]];
      if (cur == -1) {
        cur = i;
        continue;
      }
      int s = cur, t = i;
      rotate(st, st + s, st + t);
      n = t - s;
      ok = 1;
      break;
    }
    if (!ok) {
      return -1;
    }
    st[n] = st[0];
    for (int i = 0; i < n; i++) {
      assert(intersect(ls[st[i]], ls[st[i + 1]], res[i]));
    }
    return n;
  }
};
//END ALGO

const int maxn = (int) 2e5 + 10;
int n;
point o;
point ps[2 * maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  n--;
  assert(o.read());
  for (int i = 0; i < n; i++) {
    assert(ps[i].read());
  }
  return true;
}

line ls[2 * maxn];
point res[4 * maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    ps[i] = ps[i] - o;
  }
  sort(ps, ps + n, angleComp());
  for (int i = 0; i < n; i++) {
    ps[i] = ps[i] + o;
  }
  for (int i = 0; i < n; i++) {
    ps[n + i] = ps[i];
  }
  int m = 0;
  for (int i = 0, j = 0; i < n; i++) {
    if (abs((ps[i] - o) ^ (ps[i + 1] - o)) < eps) {
      printf("%.12f\n", (double) 0);
      return;
    }
    if (((ps[i] - o) ^ (ps[i + 1] - o)) < -eps) {
      continue;
    }
    ls[m++] = line(ps[i], ps[i + 1] - ps[i]);
    j = max(i, j);
    while (j < i + n && ((ps[i] - o) ^ (ps[j] - o)) > -eps) {
      j++;
    }
    if (abs((ps[i] - o) ^ (ps[j - 1] - o)) < eps) {
      printf("%.12f\n", (double) 0);
      return;
    }
    ls[m++] = line(ps[i], ps[j - 1] - ps[i]);
  }
  m = Halfplane::intersect(m, ls, res);
  if (m == -1) {
    assert(false);
  }
  res[m] = res[0];
  ld s = 0;
  for (int i = 0; i < m; i++) {
    s += (res[i] ^ res[i + 1]);
  }
  s /= 2;
  printf("%.12f\n", (double) s);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}