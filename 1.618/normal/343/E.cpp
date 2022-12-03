/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
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

#define maxn 205
int n, m;

namespace MaxFlow {
  struct Edge {
    int to, cap, rev;
  };
  vector<Edge> adj[maxn];
  int lev[maxn], iter[maxn];

  // bidirectional
  void addEdge(int u, int v, int c) {
    adj[u].push_back({v, c, (int)adj[v].size()});
    adj[v].push_back({u, c, (int)adj[u].size() - 1});
  }

  void bfs(int s) {
    memset(lev, 0x3f, sizeof(lev));
    lev[s] = 0;
    queue<int> que;
    que.push(s);
    while (que.size()) {
      int u = que.front();
      que.pop();
      for (auto e : adj[u]) {
        if (e.cap && lev[u] + 1 < lev[e.to]) {
          lev[e.to] = lev[u] + 1;
          que.push(e.to);
        }
      }
    }
  }

  int dfs(int u, int t, int f) {
    if (u == t)
      return f;
    int res = 0;
    for (int &i = iter[u]; i < (int)adj[u].size(); i++) {
      auto &e = adj[u][i];
      if (e.cap && lev[u] < lev[e.to]) {
        auto flow = dfs(e.to, t, min(e.cap, f - res));
        res += flow;
        e.cap -= flow;
        adj[e.to][e.rev].cap += flow;
        if (res == f)
          return res;
      }
    }
    return res;
  }

  int dinic(int s, int t) {
    int res = 0;
    while (true) {
      bfs(s);
      if (lev[t] == inf)
        return res;
      memset(iter, 0, sizeof(iter));
      res += dfs(s, t, inf);
    }
  }

  void undo() {
    for (int i = 1; i <= n; i++) {
      for (auto &e : adj[i]) {
        auto foo = (e.cap + adj[e.to][e.rev].cap) / 2;
        e.cap = adj[e.to][e.rev].cap = foo;
      }
    }
  }
}

vector<P> adj2[maxn];

void build(const vector<int> &nodes) {
  if (nodes.size() == 1)
    return;
  int u = nodes[0], v = nodes[1], w = MaxFlow::dinic(u, v);
  MaxFlow::undo();
  adj2[u].push_back({v, w});
  adj2[v].push_back({u, w});
  vector<int> S, T;
  for (auto i : nodes) {
    if (MaxFlow::lev[i] == inf)
      T.push_back(i);
    else
      S.push_back(i);
  }
  build(S), build(T);
}

int val;
vector<int> ans;
bool vis[maxn];

void dfs(int u, int f) {
  vis[u] = true;
  for (auto e : adj2[u]) {
    if (e.first != f)
      dfs(e.first, u);
  }
}

void solve(const vector<int> &nodes) {
  if (nodes.size() == 1) {
    ans.push_back(nodes[0]);
    return;
  }
  memset(vis, 0, sizeof(vis));
  for (auto i : nodes)
    vis[i] = true;
  int u = 0, v = 0, w = inf;
  for (auto i : nodes) {
    for (auto e : adj2[i]) {
      if (vis[e.first] && e.second < w) {
        u = i, v = e.first, w = e.second;
      }
    }
  }
  vector<int> S, T;
  memset(vis, 0, sizeof(vis));
  dfs(u, v);
  val += w;
  for (auto i : nodes) {
    if (vis[i])
      S.push_back(i);
    else
      T.push_back(i);
  }
  solve(S), solve(T);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    MaxFlow::addEdge(u, v, w);
  }
  vector<int> V;
  for (int i = 1; i <= n; i++)
    V.push_back(i);
  build(V);
  solve(V);
  printf("%d\n", val);
  for (auto i : ans)
    printf("%d ", i);
  puts("");
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
/*
6 11
1 2 10
1 6 8
2 3 4
2 5 2
2 6 3
3 4 5
3 5 4
3 6 2
4 5 7
4 6 2
5 6 3
*/