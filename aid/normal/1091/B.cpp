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
  
  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
  
  bool operator != (const point &p) const {
    return x != p.x || y != p.y;
  }
};

const int maxn = 1005;
int n;
point ps[maxn], as[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  for (int i = 0; i < n; i++) {
    as[i].read();
  }
  return true;
}

point bs[maxn];

bool check(const point &t) {
  for (int i = 0; i < n; i++) {
    bs[i] = t - ps[i];
  }
  sort(bs, bs + n);
  for (int i = 0; i < n; i++) {
    if (bs[i] != as[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  sort(as, as + n);
  for (int i = 0; i < n; i++) {
    point t = ps[0] + as[i];
    if (check(t)) {
      printf("%d %d\n", t.x, t.y);
      return;
    }
  }
  assert(false);
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