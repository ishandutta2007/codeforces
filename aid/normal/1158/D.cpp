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

  long long operator ^ (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }
};

const int maxn = 2005;
int n;
point ps[maxn];
string s;
char tmp[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int alive[maxn];
vector<int> ans;

bool cmp(const point &p, const point &q, char c) {
  if (c == 'L') {
    return (p ^ q) > 0;
  } else {
    return (p ^ q) < 0;
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    alive[i] = true;
  }
  ans.clear();
  int v = 0;
  for (int i = 1; i < n; i++) {
    if (ps[i].x < ps[v].x || (ps[i].x == ps[v].x && ps[i].y < ps[v].y)) {
      v = i;
    }
  }
  ans.push_back(v);
  alive[v] = false;
  for (int it = 0; it < n - 2; it++) {
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (!alive[i]) {
        continue;
      }
      if (u == -1 || cmp(ps[i] - ps[v], ps[u] - ps[v], s[it])) {
        u = i;
      }
    }
    v = u;
    ans.push_back(v);
    alive[v] = false;
  }
  for (int i = 0; i < n; i++) {
    if (alive[i]) {
      ans.push_back(i);
      alive[i] = false;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
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