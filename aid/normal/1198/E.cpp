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

  int d[maxn];
  vector<int> q;

  bool bfs(int s, int t) {
    for (int i = 0; i < n; i++) {
      d[i] = inf;
    }
    d[s] = 0;
    q.clear();
    q.push_back(s);
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int e = g[v][i];
        int u = es[e].to, cf = es[e].c - es[e].f;
        if (cf && d[u] == inf) {
          d[u] = d[v] + 1;
          q.push_back(u);
        }
      }
    }
    return d[t] != inf;
  }

  int pos[maxn];

  int dfs(int v, int t, int mincf) {
    if (v == t) {
      return mincf;
    }
    int res = 0;
    for (int &i = pos[v]; i < sz(g[v]); i++) {
      int e = g[v][i];
      int u = es[e].to, cf = es[e].c - es[e].f;
      if (!cf || d[u] != d[v] + 1) {
        continue;
      }
      int f = dfs(u, t, min(mincf, cf));
      if (f) {
        res += f;
        mincf -= f;
        es[e].f += f;
        es[e ^ 1].f -= f;
        if (mincf == 0) {
          break;
        }
      }
    }
    return res;
  }

  int maxFlow(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
      for (int i = 0; i < n; i++) {
        pos[i] = 0;
      }
      res += dfs(s, t, inf);
    }
    return res;
  }
}

const int maxn = 105;
int n, m;
int rs[maxn][4];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &rs[i][j]);
    }
    rs[i][0]--;
    rs[i][1]--;
  }
  return true;
}

int used[maxn][maxn];
vector<int> xs, ys;

void solve() {
  xs.clear();
  xs.push_back(0);
  xs.push_back(n);
  ys.clear();
  ys.push_back(0);
  ys.push_back(n);
  for (int i = 0; i < m; i++) {
    xs.push_back(rs[i][0]);
    ys.push_back(rs[i][1]);
    xs.push_back(rs[i][2]);
    ys.push_back(rs[i][3]);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  int h = sz(xs) - 1, w = sz(ys) - 1, vs = h + w + 2;
  int s = h + w, t = s + 1;
  Flow::init(vs);
  memset(used, 0, sizeof(used));
  for (int i = 0; i < m; i++) {
    rs[i][0] = lower_bound(xs.begin(), xs.end(), rs[i][0]) - xs.begin();
    rs[i][1] = lower_bound(ys.begin(), ys.end(), rs[i][1]) - ys.begin();
    rs[i][2] = lower_bound(xs.begin(), xs.end(), rs[i][2]) - xs.begin();
    rs[i][3] = lower_bound(ys.begin(), ys.end(), rs[i][3]) - ys.begin();
    for (int x = rs[i][0]; x < rs[i][2]; x++) {
      for (int y = rs[i][1]; y < rs[i][3]; y++) {
        if (!used[x][y]) {
          Flow::addEdge(x, h + y, inf);
          used[x][y] = true;
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    Flow::addEdge(s, i, xs[i + 1] - xs[i]);
  }
  for (int i = 0; i < w; i++) {
    Flow::addEdge(h + i, t, ys[i + 1] - ys[i]);
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