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
  int id;

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

  long long operator * (const point &p) const {
    return (long long) x * p.x + (long long) y * p.y;
  }

  long long slen() const {
    return *this * *this;
  }
};

const int maxn = (int) 1e5 + 5;
int n;
point ps[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
    ps[i].id = i;
  }
  return true;
}

const int mxlen = (int) 1.5e6;
int c[maxn];
int ans[maxn];

void solve() {
  while (true) {
    shuffle(ps, ps + n, mrand);
    point cur;
    bool bad = false;
    for (int i = 0; i < n; i++) {
      if (abs(cur.x) > inf || abs(cur.y) > inf) {
        bad = true;
        break;
      }
      point p0 = cur - ps[i];
      point p1 = cur + ps[i];
      long long s0 = p0.slen();
      long long s1 = p1.slen();
      if (s0 < s1 || (s0 == s1 && rnd(2))) {
        cur = p0;
        c[i] = -1;
      } else {
        cur = p1;
        c[i] = 1;
      }
    }
    if (bad) {
      continue;
    }
    if (cur.slen() <= (long long) mxlen * mxlen) {
      for (int i = 0; i < n; i++) {
        ans[ps[i].id] = c[i];
      }
      for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
      }
      printf("\n");
      return;
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