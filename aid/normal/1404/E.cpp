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

const int maxn = 205;
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", c[i]);
  }
  return true;
}

namespace Flow {
  struct edge {
    int to, c, f;

    edge(int to, int c): to(to), c(c), f(0) {}
  };

  const int maxn = 205 * 205;
  int n;
  vector<edge> es;
  vector<int> g[maxn];

  void init(int _n) {
    n = _n;
    es.clear();
    for (int i = 0; i < n; ++i) {
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
  int pos[maxn];
  vector<int> q;

  bool bfs(int s, int t) {
    for (int i = 0; i < n; ++i) {
      d[i] = inf;
    }
    q.clear();
    d[s] = 0;
    q.push_back(s);
    for (int l = 0; l < sz(q); ++l) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); ++i) {
        int e = g[v][i];
        int u = es[e].to, cf = es[e].c - es[e].f;
        if (!cf || d[u] <= d[v] + 1) {
          continue;
        }
        d[u] = d[v] + 1;
        q.push_back(u);
      }
    }
    return d[t] < inf;
  }

  int dfs(int v, int t) {
    if (v == t) {
      return 1;
    }
    for (int &i = pos[v]; i < sz(g[v]); ++i) {
      int e = g[v][i];
      int u = es[e].to, cf = es[e].c - es[e].f;
      if (!cf || d[u] != d[v] + 1) {
        continue;
      }
      if (dfs(u, t)) {
        ++es[e].f;
        --es[e ^ 1].f;
        return 1;
      }
    }
    return 0;
  }

  int maxFlow(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
      for (int i = 0; i < n; ++i) {
        pos[i] = 0;
      }
      while (int f = dfs(s, t)) {
        res += f;
      }
    }
    return res;
  }
}

void solve() {
  int s = n * m, t = s + 1;
  Flow::init(t + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (c[i][j] == '.') {
        continue;
      }
      {
        int nj = j + 1;
        if (nj >= m || c[i][nj] == '.') {
          Flow::addEdge(i * m + j, t, 1);
        } else {
          Flow::addEdge(i * m + j, i * m + nj, 1);
        }
      }
      {
        int ni = i + 1;
        if (ni >= n || c[ni][j] == '.') {
          Flow::addEdge(s, i * m + j, 1);
        } else {
          Flow::addEdge(ni * m + j, i * m + j, 1);
        }
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