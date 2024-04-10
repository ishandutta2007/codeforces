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

namespace Flow {
  struct edge {
    int to, c, f;

    edge(int _to, int _c): to(_to), c(_c), f(0) {}
  };

  const int maxn = 2005;
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
      if (dfs(s, t)) {
        res++;
      } else {
        break;
      }
    }
    return res;
  }
};

const int maxn = 605;
int n, m, k;
int deg[maxn];
int es[maxn][2];

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    deg[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &es[i][j]);
      es[i][j]--;
      deg[es[i][j]]++;
    }
  }
  return true;
}

vector<int> a[maxn];
int ans[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    if (2 * k < deg[i]) {
      for (int j = 0; j < m; j++) {
        printf("0 ");
      }
      printf("\n");
      return;
    }
  }
  Flow::init(n + m + 2);
  int s = n + m, t = s + 1;
  for (int i = 0; i < m; i++) {
    Flow::addEdge(s, i, 1);
    Flow::addEdge(i, m + es[i][0], 1);
    Flow::addEdge(i, m + es[i][1], 1);
  }
  for (int i = 0; i < n; i++) {
    Flow::addEdge(m + i, t, 2 * k - deg[i]);
  }
  if (Flow::maxFlow(s, t) < m) {
    for (int j = 0; j < m; j++) {
      printf("0 ");
    }
    printf("\n");
    return;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < sz(Flow::g[i]); j++) {
      int e = Flow::g[i][j];
      int vv = Flow::es[e].to, f = Flow::es[e].f;
      if (m <= vv && vv < m + n && f) {
        int v = vv - m;
        assert(es[i][0] == v || es[i][1] == v);
        if (es[i][0] == v) {
          swap(es[i][0], es[i][1]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i].clear();
  }
  for (int i = 0; i < m; i++) {
    a[es[i][0]].push_back(i);
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(a[i]); j += 2) {
      ans[a[i][j]] = c;
      if (j + 1 < sz(a[i])) {
        ans[a[i][j + 1]] = c;
      }
      c++;
    }
  }
  for (int i = 0; i < m; i++) {
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
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}