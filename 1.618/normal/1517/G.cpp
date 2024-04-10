/*
start thinking: 18:00
BULB: 20:00
result of thinking: Pure.

ymx .
?????
 #flows .

,  (x  important tent,  s, t )
t <-- o --> t
      ^
      |
s --> x <-- s
      |
      v
t <-- o --> t

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxV 2010
int lev[maxV], iter[maxV];
struct Edge {
  int to, cap, rev;
};
vector<Edge> adj[maxV];
void addEdge(int u, int v, int c) {
  adj[u].push_back((Edge){v, c, (int)adj[v].size()});
  adj[v].push_back((Edge){u, 0, (int)adj[u].size() - 1});
}
void bfs(int s) {
  memset(lev, 0x3f, sizeof(lev));
  lev[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < (int)adj[u].size(); i++) {
      Edge& e = adj[u][i];
      if (e.cap && lev[u] + 1 < lev[e.to]) {
        lev[e.to] = lev[u] + 1;
        que.push(e.to);
      }
    }
  }
}
ll dfs(int u, int t, ll f) {
  if (u == t)
    return f;
  ll b = 0;
  for (int& i = iter[u]; i < (int)adj[u].size(); i++) {
    Edge& e = adj[u][i];
    if (e.cap && lev[u] < lev[e.to]) {
      ll flow = dfs(e.to, t, min(f - b, (ll)e.cap));
      b += flow;
      e.cap -= flow;
      adj[e.to][e.rev].cap += flow;
      if (b == f)
        return f;
    }
  }
  return b;
}
ll dinic(int s, int t) {
  ll res = 0;
  while (true) {
    bfs(s);
    if (lev[t] == inf)
      return res;
    memset(iter, 0, sizeof(iter));
    res += dfs(s, t, infll);
  }
}
#undef maxV

// i in [1, n]: out; i + n: in; 2n + 1: S; 2n + 2: T.
#define maxn 1005
int n, x[maxn], y[maxn];
map<P, int> tents; // (x, y) -> (id, w)

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.);
  scanf("%d", &n);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int w;
    scanf("%d%d%d", x + i, y + i, &w);
    addEdge(i + n, i, w);
    tents[{x[i], y[i]}] = i;
    ans += w;
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] & 1) {
      if (y[i] & 1) {
        addEdge(i, 2 * n + 2, inf);
      } else {
        addEdge(2 * n + 1, i + n, inf);
        if (tents.count({x[i] - 1, y[i]}))
          addEdge(i, tents[{x[i] - 1, y[i]}] + n, inf);
        if (tents.count({x[i] + 1, y[i]}))
          addEdge(i, tents[{x[i] + 1, y[i]}] + n, inf);
      }
    } else {
      if (y[i] & 1) {
        if (tents.count({x[i] - 1, y[i]}))
          addEdge(i, tents[{x[i] - 1, y[i]}] + n, inf);
        if (tents.count({x[i] + 1, y[i]}))
          addEdge(i, tents[{x[i] + 1, y[i]}] + n, inf);
      } else {
        if (tents.count({x[i], y[i] - 1}))
          addEdge(i, tents[{x[i], y[i] - 1}] + n, inf);
        if (tents.count({x[i], y[i] + 1}))
          addEdge(i, tents[{x[i], y[i] + 1}] + n, inf);
      }
    }
  }
  printf("%lld\n", ans - dinic(2 * n + 1, 2 * n + 2));
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}