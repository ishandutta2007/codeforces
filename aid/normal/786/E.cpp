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

struct edge {
  int to, c, f;

  edge(int _to, int _c): to(_to), c(_c), f(0) {}
};

namespace Flow {
  const int maxn = (int) 4e5 + 5;
  int n;
  vector<edge> es;
  vector<int> g[maxn];
  
  void build(int _n) {
    n = _n;
    assert(n < maxn);
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
    int r = 0;
    d[s] = 0;
    q[r++] = s;
    for (int l = 0; l < r; l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int id = g[v][i];
        int u = es[id].to, cf = es[id].c - es[id].f;
        if (cf && d[u] > d[v] + 1) {
          d[u] = d[v] + 1;
          q[r++] = u;
        }
      }
    }
    return d[t] < inf;
  }

  int pos[maxn];

  int dfs(int v, int t, int mincf) {
    if (v == t) {
      return mincf;
    }
    int &i = pos[v];
    for (; i < sz(g[v]); i++) {
      int id = g[v][i];
      int u = es[id].to, cf = es[id].c - es[id].f;
      if (cf && d[u] == d[v] + 1) {
        int f = dfs(u, t, min(mincf, cf));
        if (f) {
          es[id].f += f;
          es[id ^ 1].f -= f;
          return f;
        }
      }
    }
    return 0;
  }

  int maxFlow(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
      for (int i = 0; i < n; i++) {
        pos[i] = 0;
      }
      while (int f = dfs(s, t, inf)) {
        res += f;
      }
    }
    return res;
  }

  void dfsCut(int v, int used[]) {
    used[v] = true;
    for (int i = 0; i < sz(g[v]); i++) {
      int id = g[v][i];
      int u = es[id].to, cf = es[id].c - es[id].f;
      if (cf && !used[u]) {
        dfsCut(u, used);
      }
    }
  }

  void getCut(int s, int t, int used[]) {
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    dfsCut(s, used);
  }
}

const int maxn = (int) 2e4 + 5;
const int logn = 15;
int n, m;
vector<int> g[maxn];
vector<int> gid[maxn];
int q[maxn][2];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gid[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    gid[v].push_back(i);
    g[u].push_back(v);
    gid[u].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    for (int it = 0; it < 2; it++) {
      scanf("%d", &q[i][it]);
      q[i][it]--;
    }
  }
  return true;
}

int p[maxn][logn];
int pid[maxn];
int tin[maxn], tout[maxn], t;

void dfs(int v) {
  Flow::addEdge(v, logn * n + m + 1, 1);
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
    Flow::addEdge(i * n + v, (i - 1) * n + v, inf);
    Flow::addEdge(i * n + v, (i - 1) * n + p[v][i - 1], inf);
  }
  tin[v] = t++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v][0]) {
      continue;
    }
    p[u][0] = v;
    pid[u] = gid[v][i];
    dfs(u);
  }
  tout[v] = t++;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void addOnPath(int v, int u, int id) {
  if (anc(u, v)) {
    swap(v, u);
  }
  if (!anc(v, u)) {
    for (int i = logn - 1; i >= 0; i--) {
      if (!anc(p[v][i], u)) {
        Flow::addEdge(logn * n + id, i * n + v, inf);
        v = p[v][i];
      }
    }
    Flow::addEdge(logn * n + id, v, inf);
    v = p[v][0];
  }
  assert(anc(v, u));
  swap(v, u);
  for (int i = logn - 1; i >= 0; i--) {
    if (!anc(p[v][i], u)) {
      Flow::addEdge(logn * n + id, i * n + v, inf);
      v = p[v][i];
    }
  }
  Flow::addEdge(logn * n + id, v, inf);
  v = p[v][0];
  assert(v == u);
}

vector<int> ans[2];
int cut[Flow::maxn];

void solve() {
  Flow::build(logn * n + m + 2);
  p[0][0] = 0;
  pid[0] = -1;
  t = 0;
  dfs(0);
  for (int i = 0; i < m; i++) {
    Flow::addEdge(logn * n + m, logn * n + i, 1);
    addOnPath(q[i][0], q[i][1], i);
  }
  int res = Flow::maxFlow(logn * n + m, logn * n + m + 1);
  Flow::getCut(logn * n + m, logn * n + m + 1, cut);
  ans[0].clear();
  ans[1].clear();
  for (int i = 0; i < m; i++) {
    if (!cut[logn * n + i]) {
      ans[0].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (cut[i]) {
      ans[1].push_back(pid[i]);
    }
  }
  assert(sz(ans[0]) + sz(ans[1]) == res);
  printf("%d\n", res);
  for (int it = 0; it < 2; it++) {
    printf("%d ", sz(ans[it]));
    for (int i = 0; i < sz(ans[it]); i++) {
      printf("%d ", ans[it][i] + 1);
    }
    printf("\n");
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