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
constexpr int N = 2e5 + 5;
int n, m, q, node, w[N];
vector<int> e[N], g[N];
multiset<int> s[N];
int dn, dfn[N], low[N], stc[N], tp;
void tarjan(int id) {
  low[id] = dfn[id] = ++dn, stc[++tp] = id;
  for(int it : e[id]) {
    if(!dfn[it]) {
      tarjan(it), low[id] = min(low[id], low[it]);
      if(low[it] >= dfn[id]) {
        g[++node].push_back(id);
        g[id].push_back(node);
        for(int x = 0; x != it; ) {
          g[node].push_back(x = stc[tp--]);
          g[x].push_back(node);
        }
      }
    }
    else low[id] = min(low[id], dfn[it]);
  }
}
int fa[N], sz[N], dep[N], son[N], rev[N], top[N];
void dfs1(int id, int ff) {
  dep[id] = dep[ff] + 1, fa[id] = ff, sz[id] = 1;
  for(int it : g[id]) {
    if(it == ff) continue;
    dfs1(it, id), sz[id] += sz[it];
    if(sz[it] > sz[son[id]]) son[id] = it;
  }
}
void dfs2(int id, int tp) {
  dfn[id] = ++dn, rev[dn] = id, top[id] = tp;
  if(son[id]) dfs2(son[id], tp);
  for(int it : g[id]) if(it != fa[id] && it != son[id]) dfs2(it, it);
}
int val[N << 2];
void build(int l, int r, int x) {
  if(l == r) return val[x] = w[rev[l]], void();
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
void modify(int l, int r, int p, int x) {
  if(l == r) return val[x] = w[rev[l]], void();
  int m = l + r >> 1;
  if(p <= m) modify(l, m, p, x << 1);
  else modify(m + 1, r, p, x << 1 | 1);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
int query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1, ans = 1e9;
  if(ql <= m) ans = query(l, m, ql, qr, x << 1);
  if(m < qr) ans = min(ans, query(m + 1, r, ql, qr, x << 1 | 1));
  return ans;
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m >> q, node = n;
  for(int i = 1; i <= n; i++) w[i] = read();
  for(int i = 1; i <= m; i++) {
    int a = read(), b = read();
    e[a].push_back(b), e[b].push_back(a);
  }
  tarjan(1), dfs1(1, dn = 0), dfs2(1, 1);
  for(int i = 2; i <= n; i++) s[fa[i]].insert(w[i]);
  for(int i = n + 1; i <= node; i++) w[i] = *s[i].begin();
  build(1, node, 1);
  for(int i = 1; i <= q; i++) {
    char ch;
    cin >> ch;
    int x = read(), y = read();
    if(ch == 'C') {
      if(x == 1) {
        w[x] = y, modify(1, node, dfn[x], 1);
        continue;
      }
      s[fa[x]].erase(s[fa[x]].find(w[x]));
      s[fa[x]].insert(w[x] = y);
      w[fa[x]] = *s[fa[x]].begin();
      modify(1, node, dfn[x], 1), modify(1, node, dfn[fa[x]], 1);
    }
    else {
      int ans = 1e9;
      while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = min(ans, query(1, node, dfn[top[x]], dfn[x], 1)), x = fa[top[x]];
      }
      if(dep[x] > dep[y]) swap(x, y);
      ans = min(ans, query(1, node, dfn[x], dfn[y], 1));
      if(x > n) ans = min(ans, w[fa[x]]);
      print(ans), putchar('\n');
    }
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/16
author: Alex_Wei
start coding at 19:55
finish debugging at 20:20
*/