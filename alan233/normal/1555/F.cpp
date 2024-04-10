// Author: wlzhouzhuan
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

const int N = 500005;

struct Edge {
  int to, nxt, val;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int w) {
  edge[++tot] = {v, head[u], w};
  head[u] = tot;
}

struct DSU {
  int f[N];
  void init(int n) { iota(f + 1, f + n + 1, 1); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void merge(int x, int y) { f[find(x)] = find(y); }
} dsu;

int ans[N], _u[N], _v[N], _w[N];
int root, n, q;

int dad[N], dep[N], son[N], sz[N];
int f[N][20], g[N][20];
void dfs1(int u, int fa) {
//  printf("u = %d, fa = %d\n", u, fa);
  dad[u] = fa, dep[u] = dep[fa] + 1, sz[u] = 1;
  for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1], g[u][i] = g[u][i - 1] ^ g[f[u][i - 1]][i - 1];
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    f[v][0] = u, g[v][0] = edge[i].val;
    dfs1(v, u);
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
int dfn[N], bl[N], dtot;
void dfs2(int u, int topf) {
  dfn[u] = ++dtot, bl[u] = topf;
  if (son[u]) dfs2(son[u], topf);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == dad[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}

struct SMT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  int cov[N << 2], lazy[N << 2];
  void pushup(int u) {
    cov[u] = cov[ls] | cov[rs];
  }
  void pushtag(int u, int dlt) {
    if (dlt) {
      cov[u] = 1, lazy[u] = 1;
    }
  }
  void pushdown(int u) {
    if (lazy[u]) {
      pushtag(ls, lazy[u]), pushtag(rs, lazy[u]);
      lazy[u] = 0;
    }
  }
  void update(int u, int l, int r, int ql, int qr, int dlt) {
    if (ql <= l && r <= qr) {
      pushtag(u, dlt);
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, dlt);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, dlt);
    pushup(u);
  }
  int query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return cov[u];
    pushdown(u);
    int mid = l + r >> 1;
    int qwq = 0;
    if (ql <= mid) qwq |= query(ls, l, mid, ql, qr);
    if (qr > mid) qwq |= query(rs, mid + 1, r, ql, qr);
    return qwq;
  } 
} smt;

bool chk(int u, int v) {
  while (bl[u] != bl[v]) {
    if (dep[bl[u]] < dep[bl[v]]) swap(u, v);
    if (smt.query(1, 1, n, dfn[bl[u]], dfn[u])) return 1;
    u = dad[bl[u]];
  }
  if (dfn[u] > dfn[v]) swap(u, v);
  if (dfn[u] != dfn[v] && smt.query(1, 1, n, dfn[u] + 1, dfn[v])) return 1;
  return 0;
}
void cov(int u, int v) {
  while (bl[u] != bl[v]) {
    if (dep[bl[u]] < dep[bl[v]]) swap(u, v);
    smt.update(1, 1, n, dfn[bl[u]], dfn[u], 1);
    u = dad[bl[u]];
  }
  if (dfn[u] > dfn[v]) swap(u, v);
  if (dfn[u] != dfn[v]) smt.update(1, 1, n, dfn[u] + 1, dfn[v], 1);
}

int zz(int u, int v) {
  int qaq = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[f[u][i]] >= dep[v]) {
      qaq ^= g[u][i];
      u = f[u][i];
    }
  } 
  if (u == v) return qaq;
  for (int i = 19; i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      qaq ^= g[u][i] ^ g[v][i];
      u = f[u][i], v = f[v][i];
    }
  }
  return qaq ^ g[u][0] ^ g[v][0];
}

int main() {
  memset(ans, -1, sizeof(ans));
  n = read(), q = read();
  dsu.init(n);
  for (int i = 1; i <= q; i++) {
    _u[i] = read(), _v[i] = read(), _w[i] = read();
    if (dsu.find(_u[i]) != dsu.find(_v[i])) {
      dsu.merge(_u[i], _v[i]);
      add(_u[i], _v[i], _w[i]);
      add(_v[i], _u[i], _w[i]);
      ans[i] = 1;
    }
  }
  root = (++n);
  for (int i = 1; i < n; i++) {
    if (dsu.find(i) == i) {
      add(root, i, 0);
    }
  }
  dfs1(root, 0), dfs2(root, root);
  for (int i = 1; i <= q; i++) {
    if (ans[i] != -1) { puts("YES"); continue; }
    int u = _u[i], v = _v[i];
    if (chk(u, v)) { puts("NO"); continue; }
    if (!(zz(u, v) ^ _w[i])) { puts("NO"); continue; }
    cov(u, v);
//    printf("zz = %d\n", zz(u, v));
    puts("YES");
  }
}