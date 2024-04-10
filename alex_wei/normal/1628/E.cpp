#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
bool Mbe;
constexpr int K = 20;
constexpr int N = 6e5 + 5;
struct edge {
  int u, v, w;
  bool operator < (const edge &z) const {
    return w < z.w;
  }
} e[N];
int n, q, node, fa[N], v[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int dn, dfn[N], dep[N], lg[N], mi[K][N];
vector<int> g[N];
int get(int x, int y) {return dep[x] < dep[y] ? x : y;}
void dfs(int id, int ff) {
  dep[id] = dep[ff] + 1;
  mi[0][dfn[id] = ++dn] = ff;
  for(int it : g[id]) dfs(it, id);
}
int lca(int u, int v) {
  if(u == -1) return v;
  if(v == -1) return u;
  if(u == v) return u;
  if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
  int d = lg[v - u++];
  return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}
int ori[N << 2], val[N << 2], laz[N << 2];
void tag(int x, int v) {
  if(v == 1) val[x] = ori[x];
  if(v == 2) val[x] = -1;
  laz[x] = v;
}
void down(int x) {
  if(laz[x]) {
    tag(x << 1, laz[x]);
    tag(x << 1 | 1, laz[x]);
    laz[x] = 0;
  }
}
void build(int l, int r, int x) {
  val[x] = -1;
  if(l == r) return ori[x] = l, void();
  int m = l + r >> 1;
  build(l, m, x << 1);
  build(m + 1, r, x << 1 | 1);
  ori[x] = lca(ori[x << 1], ori[x << 1 | 1]);
}
void modify(int l, int r, int ql, int qr, int x, int v) {
  if(ql <= l && r <= qr) return tag(x, v);
  int m = l + r >> 1;
  down(x);
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
  val[x] = lca(val[x << 1], val[x << 1 | 1]);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> q, node = n;
  for(int i = 1; i <= n; i++) fa[i] = i, v[i] = -1;
  for(int i = 1; i < n; i++) cin >> e[i].u >> e[i].v >> e[i].w;
  sort(e + 1, e + n);
  for(int i = 1; i < n; i++) {
    int u = find(e[i].u), v = find(e[i].v);
    ::v[++node] = e[i].w;
    g[node].push_back(u);
    g[node].push_back(v);
    fa[u] = fa[v] = fa[node] = node;
  }
  for(int i = 2; i <= node; i++) lg[i] = lg[i >> 1] + 1;
  dfs(node, 0);
  for(int i = 1; i <= lg[node]; i++)
    for(int j = 1; j + (1 << i) - 1 <= node; j++)
      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  build(1, n, 1);
  for(int i = 1; i <= q; i++) {
    int op, x, y;
    cin >> op >> x;
    if(op == 3) cout << v[lca(val[1], x)] << "\n";
    else cin >> y, modify(1, n, x, y, 1, op);
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/8/16
author: Alex_Wei
start coding at 7:52
finish debugging at 8:01
*/