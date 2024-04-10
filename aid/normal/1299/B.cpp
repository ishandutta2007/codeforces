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

  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }

  bool operator == (const point &p) const {
    return x == p.x && y == p.y;
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

vector<point> es[2];

void solve() {
  es[0].clear();
  ps[n] = ps[0];
  for (int i = 0; i < n; i++) {
    es[0].push_back(ps[i + 1] - ps[i]);
  }
  sort(es[0].begin(), es[0].end());
  es[1].clear();
  for (int i = 0; i < sz(es[0]); i++) {
    point cur = point() - es[0][i];
    es[1].push_back(cur);
  }
  sort(es[1].begin(), es[1].end());
  printf(es[0] == es[1] ? "YES\n" : "NO\n");
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