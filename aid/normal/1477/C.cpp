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
  int x, y;

  point(): x(0), y(0) {}

  point(int xx, int yy): x(xx), y(yy) {}

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

const int maxn = 5005;
int n;
point ps[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    ps[i].read();
  }
  return true;
}

int used[maxn];
int ans[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  int p = 0;
  ans[0] = p;
  used[p] = true;
  for (int it = 1; it < n; ++it) {
    int np = -1;
    long long d = -1;
    for (int i = 0; i < n; ++i) {
      if (used[i]) {
        continue;
      }
      long long curd = (ps[i] - ps[p]).slen();
      if (curd > d) {
        d = curd;
        np = i;
      }
    }
    p = np;
    ans[it] = p;
    used[p] = true;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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