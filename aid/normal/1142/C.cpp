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
};

const int maxn = (int) 1e5 + 5;
int n;
point ps[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

bool bad(const point &p0, const point &p1, const point &q) {
  long long b = (p1.y - p0.y) - ((long long) p1.x * p1.x - (long long) p0.x * p0.x);
  long long c = (long long) p0.y * (p1.x - p0.x) - (long long) p0.x * p0.x * (p1.x - p0.x) - b * p0.x;
  long long val = (long long) q.x * q.x * (p1.x - p0.x) + b * q.x + c;
  return val <= (long long) q.y * (p1.x - p0.x);
}

void solve() {
  sort(ps, ps + n);
  {
    int nn = 1;
    for (int i = 1; i < n; i++) {
      if (ps[i].x == ps[nn - 1].x) {
        ps[nn - 1] = ps[i];
      } else {
        ps[nn++] = ps[i];
      }
    }
    n = nn;
  }
  vector<point> st;
  for (int i = 0; i < n; i++) {
    while (sz(st) >= 2 && bad(st[sz(st) - 2], st[sz(st) - 1], ps[i])) {
      st.pop_back();
    }
    st.push_back(ps[i]);
  }
  printf("%d\n", sz(st) - 1);
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