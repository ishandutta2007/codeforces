#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 505;
int n, m, x;
char tmp[maxn];
int pr[maxn];
string t[maxn];
string s;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", tmp);
    t[i] = tmp;
    scanf("%d", &pr[i]);
  }
  scanf("%d", &x);
  return true;
}

struct edge {
  int to, c, f, cost;

  edge(int _to, int _c, int _cost): to(_to), c(_c), f(0), cost(_cost) {}
};

int inside[maxn], dist[maxn], p[maxn], mincf[maxn];
vector<int> g[maxn];
vector<edge> e;

void addEdge(int v, int u, int c, int cost) {
  g[v].push_back(sz(e));
  e.push_back(edge(u, c, cost));
  g[u].push_back(sz(e));
  e.push_back(edge(v, 0, -cost));
}

pair<int, int> addFlow(int s, int t, int n, int needFlow) {
  for (int i = 0; i < n; i++) {
    inside[i] = false;
    dist[i] = inf;
    p[i] = -1;
    mincf[i] = needFlow;
  }
  vector<int> q;
  dist[s] = 0;
  q.push_back(s);
  inside[s] = true;
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    inside[v] = false;
    for (int i = 0; i < sz(g[v]); i++) {
      int id = g[v][i], u = e[id].to, cf = e[id].c - e[id].f, w = e[id].cost;
      if (!cf) {
        continue;
      }
      if (dist[u] > dist[v] + w) {
        dist[u] = dist[v] + w;
        p[u] = id;
        mincf[u] = min(mincf[v], cf);
        if (!inside[u]) {
          inside[u] = true;
          q.push_back(u);
        }
      }
    }
  }
  int flow = mincf[t], price = flow * dist[t];
  for (int v = t; v != s;) {
    int id = p[v];
    e[id].f += flow;
    e[id ^ 1].f -= flow;
    v = e[id ^ 1].to;
  }
  return make_pair(flow, price);
}

int minCostFlow(int s, int t, int n, int flow) {
  int ans = 0;
  while (flow) {
    pair<int, int> f = addFlow(s, t, n, flow);
    flow -= f.first;
    ans -= f.second;
  }
  return ans;
}

void solve() {
  e.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    addEdge(i, i + 1, inf, 0);
  }
  for (int i = 0; i < m; i++) {
    int len = sz(t[i]);
    for (int j = 0; j + len <= n; j++) {
      bool ok = true;
      for (int k = 0; k < len; k++) {
        if (s[j + k] != t[i][k]) {
          ok = false;
        }
      }
      if (ok) {
        addEdge(j, j + len, 1, -pr[i]);
      }
    }
  }
  printf("%d\n", minCostFlow(0, n, n + 1, x));
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}