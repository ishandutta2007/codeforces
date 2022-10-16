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
  int x, y;

  point(): x(0), y(0) {}

  point(int _x, int _y): x(_x), y(_y) {}

  bool read() {
    return scanf("%d%d", &x, &y) == 2;
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  int operator ^ (const point &p) const {
    return x * p.y - y * p.x;
  }

  int operator * (const point &p) const {
    return x * p.x + y * p.y;
  }
};

int sgn(int x) {
  return (x > 0) - (x < 0);
}

bool checkBB(int a, int b, int c, int d) {
  if (a > b) {
    swap(a, b);
  }
  if (c > d) {
    swap(c, d);
  }
  return max(a, c) <= min(b, d);
}

bool intersect(const point &a, const point &b, const point &c, const point &d) {
  int cp0 = sgn((c - a) ^ (b - a)) * sgn((b - a) ^ (d - a)),
      cp1 = sgn((a - c) ^ (d - c)) * sgn((d - c) ^ (b - c));
  return cp0 >= 0 && cp1 >= 0 && checkBB(a.x, b.x, c.x, d.x) && checkBB(a.y, b.y, c.y, d.y);
}

ld getAngle(const point &a, const point &b) {
  return atan2(a ^ b, a * b);
}

const int n = 4;

bool inside(const point &p, point ps[n + 1]) {
  ld alpha = 0;
  for (int i = 0; i < n; i++) {
    alpha += getAngle(ps[i] - p, ps[i + 1] - p);
  }
  return abs(alpha) > 0.5;
}

point ps[2][n + 1];

int read() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      if (!ps[i][j].read()) {
        return false;
      }
    }
    ps[i][n] = ps[i][0];
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (intersect(ps[0][i], ps[0][i + 1], ps[1][j], ps[1][j + 1])) {
        printf("YES\n");
        return;
      }
    }
  }
  for (int it = 0; it < 2; it++) {
    for (int i = 0; i < n; i++) {
      if (inside(ps[it][i], ps[!it])) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
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