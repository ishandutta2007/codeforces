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

namespace Flow {

  struct edge {
    int to, c, f;

    edge(int _to, int _c): to(_to), c(_c), f(0) {}
  };

  const int maxn = 3005;
  int n;
  vector<edge> es;
  vector<int> g[maxn];

  void addEdge(int v, int u, int c) {
    g[v].push_back(sz(es));
    es.push_back(edge(u, c));
    g[u].push_back(sz(es));
    es.push_back(edge(v, 0));
  }

  void init(int _n) {
    n = _n;
    es.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  int d[maxn];
  vector<int> q;

  bool bfs(int s, int t) {
    for (int i = 0; i < n; i++) {
      d[i] = inf;
    }
    q.clear();
    d[s] = 0;
    q.push_back(s);
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int e = g[v][i];
        int u = es[e].to, cf = es[e].c - es[e].f;
        if (!cf || d[u] < inf) {
          continue;
        }
        d[u] = d[v] + 1;
        q.push_back(u);
      }
    }
    return d[t] < inf;
  }

  int p[maxn];

  int dfs(int v, int t, int mincf) {
    if (v == t) {
      return mincf;
    }
    int res = 0;
    for (auto &i = p[v]; i < sz(g[v]); i++) {
      int e = g[v][i];
      int u = es[e].to, cf = es[e].c - es[e].f;
      if (d[u] != d[v] + 1 || !cf) {
        continue;
      }
      int f = dfs(u, t, min(mincf, cf));
      if (f) {
        res += f;
        mincf -= f;
        es[e].f += f;
        es[e ^ 1].f -= f;
        if (!mincf) {
          break;
        }
      }
    }
    return res;
  }

  int maxFlow(int s, int t) {
    int res = 0;
    while (true) {
      if (!bfs(s, t)) {
        break;
      }
      for (int i = 0; i < n; i++) {
        p[i] = 0;
      }
      res += dfs(s, t, inf);
    }
    return res;
  }
}

const int maxn = 55;
int n, h, m;
int ls[maxn], rs[maxn], xs[maxn], cs[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &h, &m) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &ls[i], &rs[i], &xs[i], &cs[i]);
    ls[i]--;
  }
  return true;
}

void solve() {
  int s = n * (h + 1) + m, t = s + 1;
  Flow::init(t + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= h; j++) {
      int v = i * (h + 1) + j;
      Flow::addEdge(s, v, 2 * j - 1);
      Flow::addEdge(v, v - 1, inf);
      for (int k = 0; k < m; k++) {
        if (ls[k] <= i && i < rs[k] && j > xs[k]) {
          Flow::addEdge(v, n * (h + 1) + k, inf);
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    Flow::addEdge(n * (h + 1) + i, t, cs[i]);
  }
  printf("%d\n", h * h * n - Flow::maxFlow(s, t));
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