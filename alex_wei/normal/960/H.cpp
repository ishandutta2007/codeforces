#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 5e4 + 5;
constexpr int K = 1.5e7 + 5;
int n, m, q, C, a[N], fa[N], b[N];
vector<int> e[N];
int sz[N], son[N], dep[N];
int dn, dfn[N], rev[N], top[N];
void dfs1(int id) {
  sz[id] = 1, dep[id] = dep[fa[id]] + 1;
  for(int it : e[id]) {
    dfs1(it);
    sz[id] += sz[it];
    if(sz[it] > sz[son[id]]) son[id] = it;
  }
}
void dfs2(int id, int tp) {
  top[id] = tp, rev[dfn[id] = ++dn] = id;
  if(son[id]) dfs2(son[id], tp);
  for(int it : e[id]) if(it != son[id]) dfs2(it, it);
}
struct dat {
  ll s, sq;
  dat operator + (const dat &x) {return {s + x.s, sq + x.sq};}
} val[K];
int node, R[N], ls[K], rs[K], laz[K];
void tag(int &x, int v, int len) {
  if(!x) x = ++node;
  laz[x] += v;
  val[x].sq += 2ll * v * val[x].s + 1ll * len * v * v;
  val[x].s += 1ll * len * v;
}
void down(int l, int r, int x) {
  if(laz[x]) {
    int m = l + r >> 1;
    tag(ls[x], laz[x], m - l + 1);
    tag(rs[x], laz[x], r - m);
    laz[x] = 0;
  }
}
void modify(int l, int r, int ql, int qr, int &x, int v) {
  if(!x) x = ++node;
  if(ql <= l && r <= qr) return tag(x, v, r - l + 1);
  int m = l + r >> 1;
  down(l, r, x);
  if(ql <= m) modify(l, m, ql, qr, ls[x], v);
  if(m < qr) modify(m + 1, r, ql, qr, rs[x], v);
  val[x] = val[ls[x]] + val[rs[x]];
}
void modify(int c, int x, int v) {
  while(x) modify(1, n, dfn[top[x]], dfn[x], R[c], v), x = fa[top[x]];
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m >> q >> C;
  for(int i = 1; i <= n; i++) a[i] = read();
  for(int i = 2; i <= n; i++) e[fa[i] = read()].push_back(i);
  for(int i = 1; i <= m; i++) b[i] = read();
  dfs1(1), dfs2(1, 1);
  for(int i = 1; i <= n; i++) modify(a[i], i, 1);
  for(int _ = 1; _ <= q; _++) {
    int op = read(), x = read();
    if(op == 1) modify(a[x], x, -1), modify(a[x] = read(), x, 1);
    else {
      ll ans = b[x] * b[x] * val[R[x]].sq - 2 * C * b[x] * val[R[x]].s + 1ll * n * C * C;
      printf("%.9lf\n", 1.0 * ans / n);
    }
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/16
author: Alex_Wei
start coding at
finish debugging at 19:32
*/