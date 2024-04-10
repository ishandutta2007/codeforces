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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

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

  const int maxn = 105;
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
  int q[maxn];

  bool bfs(int s, int t) {
    for (int i = 0; i < n; i++) {
      d[i] = inf;
    }
    d[s] = 0;
    int qr = 0;
    q[qr++] = s;
    for (int ql = 0; ql < qr; ql++) {
      int v = q[ql];
      for (int i = 0; i < sz(g[v]); i++) {
        int id = g[v][i], u = es[id].to, cf = es[id].c - es[id].f;
        if (cf && d[u] >= inf) {
          d[u] = d[v] + 1;
          q[qr++] = u;
        }
      }
    }
    return d[t] < inf;
  }

  int pos[maxn];

  bool dfs(int v, int t) {
    if (v == t) {
      return true;
    }
    for (int &i = pos[v]; i < sz(g[v]); i++) {
      int id = g[v][i], u = es[id].to, cf = es[id].c - es[id].f;
      if (d[u] == d[v] + 1 && cf && dfs(u, t)) {
        es[id].f++;
        es[id ^ 1].f--;
        return true;
      }
    }
    return false;
  }

  int maxFlow(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
      for (int i = 0; i < n; i++) {
        pos[i] = 0;
      }
      while (dfs(s, t)) {
        res++;
      }
    }
    return res;
  }

  vector<int> used;

  void getCut(int v) {
    used[v] = true;
    for (int i = 0; i < sz(g[v]); i++) {
      int id = g[v][i];
      int u = es[id].to, cf = es[id].c - es[id].f;
      if (!cf || used[u]) {
        continue;
      }
      getCut(u);
    }
  }

  vector<int> minCut(int s, int t) {
    maxFlow(s, t);
    used.clear();
    used.resize(n, false);
    getCut(s);
    return used;
  }
};

const int maxn = 105, maxm = 1005;
int n, m, s, t;
vector< pair<int, int> > g[maxn];
vector<int> ids[maxn];

int read() {
  if (scanf("%d%d%d%d", &n, &m, &s, &t) < 4) {
    return false;
  }
  s--;
  t--;
  for (int i = 0; i < n; i++) {
    g[i].clear();
    ids[i].clear();
  }
  Flow::init(n);
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    g[v].push_back(make_pair(u, w));
    ids[v].push_back(i);
    if (w) {
      Flow::addEdge(v, u, 1);
      Flow::addEdge(u, v, inf);
    } else {
      Flow::addEdge(v, u, inf);
    }
  }
  return true;
}

int f[maxm];
int c[maxm];
int used[maxn];
int curu;

bool addFlow(int v, int t) {
  if (v == t) {
    return true;
  }
  used[v] = curu;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (w == 0 || used[u] == curu) {
      continue;
    }
    if (addFlow(u, t)) {
      f[ids[v][i]]++;
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < m; i++) {
    f[i] = 0;
  }
  g[t].push_back(make_pair(s, -1));
  ids[t].push_back(m);
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].first, w = g[v][i].second;
      if (w != 1) {
        continue;
      }
      int id = ids[v][i];
      if (f[id]) {
        continue;
      }
      curu++;
      assert(addFlow(u, v));
      f[id]++;
    }
  }
  vector<int> cut = Flow::minCut(s, t);
  int res = 0;
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].first, id = ids[v][i];
      if (cut[v] && !cut[u]) {
        c[id] = f[id];
        res++;
      } else {
        c[id] = (int) 1e9;
      }
    }
  }
  printf("%d\n", res);
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", f[i], c[i]);
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