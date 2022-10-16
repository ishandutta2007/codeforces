#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 1e5 + 5;
bool laz[N << 2];
int len[N << 2];
struct dat {
  int sum, suf;
  dat operator + (const dat &x) {return {sum + x.sum, max(x.suf, suf + x.sum)};}
} val[N << 2];
void tag(int x) {val[x] = {-len[x], -1}, laz[x] = 1;}
void down(int x) {if(laz[x]) tag(x << 1), tag(x << 1 | 1), laz[x] = 0;}
void build(int l, int r, int x) {
  len[x] = r - l + 1, val[x] = {-len[x], -1};
  if(l == r) return;
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
}
void modify(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return tag(x);
  int m = l + r >> 1;
  down(x);
  if(ql <= m) modify(l, m, ql, qr, x << 1);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
void toggle(int l, int r, int p, int x, int v, int type) {
  if(l == r) return val[x].sum = val[x].suf = type ? v : val[x].sum + v, void();
  int m = l + r >> 1;
  down(x);
  if(p <= m) toggle(l, m, p, x << 1, v, type);
  else toggle(m + 1, r, p, x << 1 | 1, v, type);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
dat query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  dat ans = {0, -1};
  down(x);
  if(m < qr) ans = query(m + 1, r, ql, qr, x << 1 | 1) + ans;
  if(ql <= m) ans = query(l, m, ql, qr, x << 1) + ans;
  return ans;
}
int n, q;
vector<int> e[N];
int sz[N], dep[N], fa[N], son[N];
int dn, dfn[N], top[N];
void dfs1(int id) {
  sz[id] = 1, dep[id] = fa[id] + 1;
  for(int it : e[id]) {
    dfs1(it), sz[id] += sz[it];
    if(sz[it] > sz[son[id]]) son[id] = it;
  }
}
void dfs2(int id, int tp) {
  dfn[id] = ++dn, top[id] = tp;
  if(son[id]) dfs2(son[id], tp);
  for(int it : e[id]) if(it != son[id]) dfs2(it, it);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 2; i <= n; i++) cin >> fa[i], e[fa[i]].push_back(i);
  dfs1(1), dfs2(1, 1);
  build(1, n, 1);
  for(int i = 1; i <= q; i++) {
    int op, x;
    cin >> op >> x;
    if(op == 1) toggle(1, n, dfn[x], 1, 1, 0);
    if(op == 2) {
      modify(1, n, dfn[x], dfn[x] + sz[x] - 1, 1);
      dat cur = {0, -1};
      int u = fa[x];
      while(u) cur = query(1, n, dfn[top[u]], dfn[u], 1) + cur, u = fa[top[u]];
      if(cur.suf >= 0) toggle(1, n, dfn[x], 1, -cur.suf - 1, 1);
    }
    if(op == 3) {
      dat cur = {0, -1};
      while(x && cur.suf < 0) cur = query(1, n, dfn[top[x]], dfn[x], 1) + cur, x = fa[top[x]];
      if(cur.suf >= 0) puts("black");
      else puts("white");
    }
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/8
author: Alex_Wei
start coding at 13:00
finish debugging at 13:45
*/