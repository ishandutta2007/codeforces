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
    int to, c, cost, f;
    
    edge(int _to, int _c, int _cost): to(_to), c(_c), cost(_cost), f(0) {}
  };

  const int maxn = 55;
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

  void addEdge(int v, int u, int c, int cost) {
    g[v].push_back(sz(es));
    es.push_back(edge(u, c, cost));
    g[u].push_back(sz(es));
    es.push_back(edge(v, 0, -cost));
  }

  int d[maxn];
  int p[maxn], pe[maxn];
  int inside[maxn];
  vector<int> q;

  int pushFlow(int s, int t) {
    q.clear();
    for (int i = 0; i < n; i++) {
      d[i] = inf;
      p[i] = -1;
      pe[i] = -1;
      inside[i] = false;
    }
    d[s] = 0;
    q.push_back(s);
    inside[s] = true;
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      inside[v] = false;
      for (int i = 0; i < sz(g[v]); i++) {
        int e = g[v][i];
        int u = es[e].to, cf = es[e].c - es[e].f, w = es[e].cost;
        if (!cf) {
          continue;
        }
        if (d[v] + w < d[u]) {
          d[u] = d[v] + w;
          p[u] = v;
          pe[u] = e;
          if (!inside[u]) {
            q.push_back(u);
            inside[u] = true;
          }
        }
      }
    }
    if (d[t] >= 0) {
      return 0;
    }
    int res = d[t];
    for (int v = t; v != s; v = p[v]) {
      int e = pe[v];
      es[e].f++;
      es[e ^ 1].f--;
    }
    return res;
  }

  int minCost(int s, int t) {
    int cost = 0;
    while (int c = pushFlow(s, t)) {
      cost += c;
    }
    return cost;
  }
}

const int maxn = 55;
int n, m;
int g[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = -1;
    }
    g[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v][u] = 1;
    g[u][v] = 0;
  }
  return true;
}

int deg[maxn];

void solve() {
  int s = n, t = n + 1;
  Flow::init(n + 2);
  for (int v = 0; v < n; v++) {
    deg[v] = 0;
  }
  for (int v = 0; v < n; v++) {
    for (int u = v + 1; u < n; u++) {
      if (g[v][u] != -1) {
        deg[v] += g[v][u];
        deg[u] += g[u][v];
        continue;
      }
      deg[v]++;
      Flow::addEdge(u, v, 1, 0);
    }
  }
  for (int v = 0; v < n; v++) {
    int pr = deg[v] * (n - 1 - deg[v]);
    for (int i = deg[v] + 1; i <= n - 1; i++) {
      int cur = i * (n - 1 - i);
      Flow::addEdge(s, v, 1, pr - cur);
      pr = cur;
    }
    pr = deg[v] * (n - 1 - deg[v]);
    for (int i = deg[v] - 1; i >= 0; i--) {
      int cur = i * (n - 1 - i);
      Flow::addEdge(v, t, 1, pr - cur);
      pr = cur;
    }
  }
  Flow::minCost(s, t);
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(Flow::g[v]); i++) {
      int e = Flow::g[v][i];
      int u = Flow::es[e].to;
      if (u >= n) {
        continue;
      }
      int f = Flow::es[e].f;
      if (f) {
        g[v][u] = 1;
        g[u][v] = 0;
      } else {
        g[u][v] = 1;
        g[v][u] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", g[i][j]);
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