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
    return (scanf("%d%d", &x, &y) == 2);
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

  long long operator * (const point&p) const {
    return (long long) x * p.x + (long long) y * p.y;
  }

  long long slen() const {
    return *this * *this;
  }

  int type() const {
    return x < 0 || (x == 0 && y < 0);
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  return (a ^ b) > 0;
}

ld getAlpha(const point &a, const point &b) {
  return atan2((ld) (a ^ b), (ld) (a * b));
}

bool checkPoint(const point &a, long long d) {
  return a.slen() < d * d;
}

bool checkSeg(const point &a, const point &b, long long d) {
  if (((point(0, 0) - a) * (b - a)) < 0) {
    return checkPoint(a, d);
  }
  if (((point(0, 0) - b) * (a - b)) < 0) {
    return checkPoint(b, d);
  }
  long long x = (a ^ b);
  x = x * x;
  long long y = d * d * (b - a).slen();
  return x < y;
}

bool check(const vector<point> &pol, long long d) {
  for (int i = 0; i + 1 < sz(pol); i++) {
    if (checkSeg(pol[i], pol[i + 1], d)) {
      return true;
    }
  }
  {
    ld alpha = 0;
    for (int i = 0; i + 1 < sz(pol); i++) {
      alpha += getAlpha(pol[i], pol[i + 1]);
    }
    if (alpha > 0.5) {
      return true;
    }
  }
  return false;
}

const int maxn = 205;
int w;
vector<point> pol;
int m;
point qs[maxn];
int rs[maxn];

int read() {
  int n;
  if (scanf("%d%d", &n, &w) < 2) {
    return false;
  }
  pol.resize(n);
  for (int i = 0; i < n; i++) {
    pol[i].read();
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    qs[i].read();
    scanf("%d", &rs[i]);
  }
  return true;
}

namespace Flow {

  struct edge {
    int to, c, f;

    edge(int _to, int _c): to(_to), c(_c), f(0) {}
  };

  const int maxn = 505;
  int n;
  vector<edge> es;
  vector<int> g[maxn];

  void init(int _n) {
    n = _n;
    es.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  void addEdge(int v, int u, int c) {
    g[v].push_back(sz(es));
    es.push_back(edge(u, c));
    g[u].push_back(sz(es));
    es.push_back(edge(v, 0));
  }

  int used[maxn];

  bool dfs(int v, int t) {
    used[v] = true;
    if (v == t) {
      return true;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int e = g[v][i];
      int u = es[e].to, cf = es[e].c - es[e].f;
      if (!used[u] && cf && dfs(u, t)) {
        es[e].f++;
        es[e ^ 1].f--;
        return true;
      }
    }
    return false;
  }

  int maxFlow(int s, int t) {
    int res = 0;
    while (true) {
      for (int i = 0; i < n; i++) {
        used[i] = false;
      }
      if (!dfs(s, t)) {
        break;
      }
      res++;
    }
    return res;
  }
};

void solve() {
  {
    int pos = 0;
    for (int i = 1; i < sz(pol); i++) {
      if (pol[i].x < pol[pos].x || (pol[i].x == pol[pos].x && pol[i].y < pol[pos].y)) {
        pos = i;
      }
    }
    rotate(pol.begin(), pol.begin() + pos, pol.end());
    point p0 = pol[0];
    for (int i = 0; i < sz(pol); i++) {
      pol[i] = pol[i] - p0;
    }
    pol.push_back(pol[0]);
  }
  int wpol = 0;
  for (int i = 0; i < sz(pol); i++) {
    wpol = max(wpol, pol[i].x);
  }
  w -= wpol;
  vector<point> psum;
  {
    vector<point> qol = pol;
    qol.pop_back();
    for (int i = 0; i < sz(qol); i++) {
      qol[i] = point(0, 0) - qol[i];
    }
    {
      int pos = 0;
      for (int i = 1; i < sz(qol); i++) {
        if (qol[i].x < qol[pos].x || (qol[i].x == qol[pos].x && qol[i].y < qol[pos].y)) {
          pos = i;
        }
      }
      rotate(qol.begin(), qol.begin() + pos, qol.end());
    }
    qol.push_back(qol[0]);
    point p0 = qol[0];
    vector<point> es0, es1, es;
    for (int i = 0; i + 1 < sz(pol); i++) {
      es0.push_back(pol[i + 1] - pol[i]);
    }
    for (int i = 0; i + 1 < sz(qol); i++) {
      es1.push_back(qol[i + 1] - qol[i]);
    }
    es.resize(sz(es0) + sz(es1));
    merge(es0.begin(), es0.end(), es1.begin(), es1.end(), es.begin());
    psum.push_back(p0);
    for (int i = 0; i < sz(es); i++) {
      p0 = p0 + es[i];
      psum.push_back(p0);
    }
  }
  int s = 2 * m, t = s + 1;
  Flow::init(t + 1);
  for (int i = 0; i < m; i++) {
    Flow::addEdge(2 * i, 2 * i + 1, 1);
    int l = qs[i].x - wpol - rs[i], r = qs[i].x + rs[i];
    if (l < 0) {
      Flow::addEdge(s, 2 * i, inf);
    }
    if (w < r) {
      Flow::addEdge(2 * i + 1, t, inf);
    }
    for (int j = i + 1; j < m; j++) {
      vector<point> cur = psum;
      {
        point toadd = qs[j] - qs[i];
        for (int it = 0; it < sz(cur); it++) {
          cur[it] = cur[it] + toadd;
        }
      }
      int curr = rs[i] + rs[j];
      if (check(cur, curr)) {
        Flow::addEdge(2 * i + 1, 2 * j, inf);
        Flow::addEdge(2 * j + 1, 2 * i, inf);
      }
    }
  }
  printf("%d\n", Flow::maxFlow(s, t));
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