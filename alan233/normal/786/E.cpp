// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
const int M = 1000005;
const int inf = 1e9;

vector<pii> adj[N];
int n, m;

int faid[N];
int sz[N], son[N], dep[N], dad[N];
void dfs1(int u, int fa) {
  sz[u] = 1, dep[u] = dep[fa] + 1, dad[u] = fa;
  for (auto v: adj[u]) {
    if (v.fir == fa) continue;
    faid[v.fir] = v.sec;
    dfs1(v.fir, u);
    sz[u] += sz[v.fir];
    if (sz[v.fir] > sz[son[u]]) son[u] = v.fir; 
  }
}
int dfn[N], did[N], top[N], clen[N], cid[N], dtot;
void dfs2(int u, int topf) {
  dfn[u] = ++dtot, did[dtot] = u, top[u] = topf, clen[topf]++;
  if (son[u]) dfs2(son[u], topf);
  for (auto v: adj[u]) {
    if (dep[v.fir] < dep[u] || v.fir == son[u]) continue;
    dfs2(v.fir, v.fir);
  }
}

int S, T, tot;

namespace FLOW {
struct Edge {
  int to, nxt, cap;
} edge[M << 1];
int head[N], etot = 1;
inline void add(int u, int v, int cap) {
  edge[++etot] = {v, head[u], cap};
  head[u] = etot;
}
inline void addedge(int u, int v, int cap) {
  add(u, v, cap);
  add(v, u, 0);
}
int dis[N], cur[N];
inline bool bfs(int S, int T) {
  queue<int> q;
  rep(i, 1, tot) cur[i] = head[i], dis[i] = inf;
  dis[S] = 0, q.push(S);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to, cap = edge[i].cap;
      if (dis[v] == inf && cap) {
        dis[v] = dis[u] + 1;
        q.push(v);
      } 
    }
  } 
  return dis[T] != inf;
}
int dfs(int u, int T, int now) {
  if (u == T) return now;
  int over = 0;
  for (int &i = cur[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, cap = edge[i].cap;
    if (dis[v] == dis[u] + 1 && cap) {
      int go = dfs(v, T, min(now, cap));
      now -= go, over += go;
      edge[i].cap -= go, edge[i ^ 1].cap += go;
      if (!go) dis[v] = inf;
      if (!now) break;
    }
  }
  return over;
}
int Dinic(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) flow += dfs(S, T, inf);
  return flow;
}
bool vis[N];
void sol_dfs(int u) {
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, cap = edge[i].cap;
    if (!vis[v] && cap) {
      vis[v] = 1;
      sol_dfs(v);
    }
  }
}
inline void sol() { // 
  sol_dfs(S);
  vector<int> tmp1, tmp2;
  for (int i = 1; i <= m; i++) {
    if (!vis[n + i])
      tmp1.pb(i);
  }
//  assert(!vis[T]);
  for (int i = 2; i <= n; i++) {
    if (vis[i])
      tmp2.pb(faid[did[i]]);
  }
  print(SZ(tmp1)); for (auto v: tmp1) putchar(' '), print(v);
  puts("");
  print(SZ(tmp2)); for (auto v: tmp2) putchar(' '), print(v);
  puts("");
}
}

#define ls (u << 1)
#define rs (u << 1 | 1)
int node[N << 2];
void build(int u, int l, int r) {
//  printf("build %d %d %d\n", u, l, r);
  if (l == r) {
    node[u] = l;
    return ;
  }
  node[u] = ++tot;
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  FLOW::addedge(node[u], node[ls], inf);
  FLOW::addedge(node[u], node[rs], inf);
}
void query(int u, int l, int r, int ql, int qr, int id) {
  if (ql <= l && r <= qr) {
    FLOW::addedge(id, node[u], inf);
    return ;
  }
  int mid = l + r >> 1;
  if (ql <= mid) query(ls, l, mid, ql, qr, id);
  if (qr > mid) query(rs, mid + 1, r, ql, qr, id);
}

inline void sol(int u, int v, int id) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    if (dfn[u] == dfn[top[u]] + clen[top[u]] - 1) FLOW::addedge(id, cid[top[u]], inf);
    else query(1, 1, n, dfn[top[u]], dfn[u], id);
    u = dad[top[u]];
  }  
  if (dep[u] > dep[v]) swap(u, v);
  if (u != v) query(1, 1, n, dfn[u] + 1, dfn[v], id);
}

int main() {
  n = read(), m = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb({v, i}), adj[v].pb({u, i});
  }
  dfs1(1, 0), dfs2(1, 1);
//  cerr << "!\n";
  tot = n + m + 2, S = n + m + 1, T = n + m + 2;
  build(1, 1, n);
//  cerr << "!!\n";
  rep(i, 1, n) {
    if (top[i] == i) {
      cid[i] = ++tot;
      query(1, 1, n, dfn[i], dfn[i] + clen[i] - 1, cid[i]);
    }
  }
  rep(i, 1, m) {
    int u = read(), v = read();
    FLOW::addedge(S, n + i, 1);
    sol(u, v, n + i);
  }
  rep(i, 2, n) {
    FLOW::addedge(i, T, 1);
  }
  print(FLOW::Dinic(S, T), '\n');
  FLOW::sol();
  return 0;
}