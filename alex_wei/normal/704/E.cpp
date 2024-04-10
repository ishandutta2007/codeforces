#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ull = unsigned long long;
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
constexpr int K = N * 40;
struct frac {
  ll a, b;
  frac(ll x = 0, ll y = 1) {a = x, b = y;}
  bool operator < (const frac &x) const {return a * x.b < b * x.a;}
  bool operator > (const frac &x) const {return a * x.b < b * x.a;}
  bool operator <= (const frac &x) const {return a * x.b <= b * x.a;}
  bool operator == (const frac &x) const {return a * x.b == b * x.a;}
  frac operator + (const frac &x) const {return frac(a * x.b + b * x.a, b * x.b);}
  frac operator - (const frac &x) const {return frac(a * x.b - b * x.a, b * x.b);}
  frac operator * (const int &x) const {return frac(a * x, b);}
  double get() {return 1.0 * a / b;}
} be[K], ed[K];
int n, m, cnt, k[K], b[K];
vector<int> e[N], buc[N];
int sz[N], son[N], fa[N], dep[N];
int dn, dfn[N], rev[N], top[N];
void dfs1(int id, int ff) {
  fa[id] = ff, dep[id] = dep[ff] + 1, sz[id] = 1;
  for(int it : e[id]) {
    if(it == ff) continue;
    dfs1(it, id);
    sz[id] += sz[it];
    if(sz[it] > sz[son[id]]) son[id] = it;
  }
}
void dfs2(int id, int tp) {
  top[id] = tp, rev[dfn[id] = ++dn] = id;
  if(son[id]) dfs2(son[id], tp);
  for(int it : e[id]) if(it != fa[id] && it != son[id]) dfs2(it, it);
}
int dis(int u, int v) {
  int ans = 0;
  while(top[u] != top[v]) {
    if(dep[top[u]] < dep[top[v]]) swap(u, v);
    ans += dep[u] - dep[fa[top[u]]], u = fa[top[u]];
  }
  return ans + abs(dep[u] - dep[v]);
}
frac T, S;
struct cmp {
  bool operator () (const int &x, const int &y) const {
    frac Px = T * k[x] + b[x], Py = T * k[y] + b[y];
    return Px == Py ? x < y : Px < Py;
  }
};
double solve(vector<int> &buc) {
  if(buc.size() <= 1) return 1e9;
  sort(buc.begin(), buc.end(), [&](int x, int y) {
    frac Tx = x > 0 ? be[x] : ed[-x], Ty = y > 0 ? be[y] : ed[-y];
    return Tx == Ty ? x > y : Tx < Ty;
  });
  S = 0x3f3f3f3f;
  set<int, cmp> s;
  auto check = [&](int x, int y) {
    frac L = max(be[x], be[y]), R = min(ed[x], ed[y]);
    if(R < L) return;
    if(k[x] == k[y]) {if(b[x] == b[y]) S = min(S, L);}
    else {
      frac X = frac(b[y] - b[x], k[x] - k[y]);
      if(X.b < 0) X.a = -X.a, X.b = -X.b;
      if(L <= X && X <= R) S = min(S, X);
    }
  };
  for(int it : buc) {
    int id = abs(it);
    T = it < 0 ? ed[id] : be[id];
    if(S <= T) return S.get();
    if(it < 0) {
      auto pt = s.find(id), pre = pt, suf = pt;
      if(pt != s.begin() && pt != --s.end()) check(*--pre, *++suf);
      s.erase(pt);
    }
    else {
      s.insert(id);
      auto pt = s.find(id), pre = pt, suf = pt;
      if(pt != s.begin()) check(*--pre, *pt);
      if(pt != --s.end()) check(*++suf, *pt);
    }
  }
  return 1e9;
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs1(1, 0), dfs2(1, 1);
  for(int i = 1; i <= m; i++) {
    int t, c, u, v;
    cin >> t >> c >> u >> v;
    int e = (t *= c) + dis(u, v);
    while(top[u] != top[v]) {
      if(dep[top[u]] > dep[top[v]]) {
        buc[top[u]].push_back(++cnt);
        buc[top[u]].push_back(-cnt);
        k[cnt] = -c;
        b[cnt] = dep[u] + t;
        be[cnt] = frac(t, c);
        t += dep[u] - dep[fa[top[u]]];
        ed[cnt] = frac(t, c);
        u = fa[top[u]];
      }
      else {
        buc[top[v]].push_back(++cnt);
        buc[top[v]].push_back(-cnt);
        k[cnt] = c;
        b[cnt] = dep[v] - e;
        ed[cnt] = frac(e, c);
        e -= dep[v] - dep[fa[top[v]]];
        be[cnt] = frac(e, c);
        v = fa[top[v]];
      }
    }
    buc[top[u]].push_back(++cnt);
    buc[top[u]].push_back(-cnt);
    be[cnt] = frac(t, c);
    ed[cnt] = frac(e, c);
    if(dep[u] < dep[v]) k[cnt] = c, b[cnt] = dep[u] - t;
    else k[cnt] = -c, b[cnt] = dep[u] + t;
  }
  double ans = 1e9;
  for(int i = 1; i <= n; i++) ans = min(ans, solve(buc[i]));
  if(ans > 1e8) puts("-1");
  else printf("%.9lf\n", ans);
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/16
author: Alex_Wei
start coding at 7:40
finish debugging at 9:09
*/