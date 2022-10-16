#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct Edge {
  int to, c, f, cost;

  Edge(int _to, int _c, int _cost): to(_to), c(_c), f(0), cost(_cost) {}
};

const int maxn = 3005;
int n;
int a[maxn], dif[maxn];
int dist[maxn], p[maxn], mincf[maxn], inside[maxn];
vector<int> g[maxn];
vector<Edge> e;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void addEdge(int v, int u, int c, int cost) {
  g[v].push_back(sz(e));
  e.push_back(Edge(u, c, cost));
  g[u].push_back(sz(e));
  e.push_back(Edge(v, 0, -cost));
}

pair<int, long long> addFlow(int s, int t, int n, int needFlow) {
  for (int i = 0; i < n; i++) {
    dist[i] = inf;
    p[i] = -1;
    mincf[i] = needFlow;
    inside[i] = false;
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
  int flow = mincf[t];
  long long cost = (long long)flow * dist[t];
  for (int v = t; v != s;) {
    int id = p[v];
    e[id].f += flow;
    e[id ^ 1].f -= flow;
    v = e[id ^ 1].to;
  }
  return make_pair(flow, cost);
}

long long minCostFlow(int s, int t, int n, long long needFlow) {
  long long flow = 0, cost = 0;
  while (flow < needFlow) {
    pair<int, long long> f = addFlow(s, t, n, min((long long)inf, needFlow - flow));
    flow += f.first;
    cost += f.second;
  }
  return cost;
}

void solve() {
  for (int i = 0; i + 1 < n; i++) {
    dif[i] = a[i + 1] - a[i];
  }
  n--;
  int s = n, t = s + 1;
  for (int i = 0; i <= t; i++) {
    g[i].clear();
  }
  e.clear();
  long long needFlow = 0;
  for (int i = 0; i < n; i++) {
    if (dif[i] > 1) {
      addEdge(s, i, dif[i] - 1, 0);
    }
    else if (dif[i] < 1) {
      addEdge(i, t, -dif[i] + 1, 0);
      needFlow += -dif[i] + 1;
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    addEdge(i, i + 1, inf, 1);
    addEdge(i + 1, i, inf, 1);
  }
  addEdge(s, 0, inf, 1);
  addEdge(s, n - 1, inf, 1);
  printf("%I64d\n", minCostFlow(s, t, t + 1, needFlow));
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}