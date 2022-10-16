#include <bits/stdc++.h>
using namespace std;
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
constexpr int K = 18;
constexpr int N = 2e5 + 5;
constexpr int base = 1e9 + 7; // base should be larger than N
constexpr int mod = 1004535809;
inline int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int n, m, q, lg;
vector<pii> e[N];
int dn, dep[N], fc[N], sz[N], dfn[N];
bool isanc(int u, int v) {return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + sz[u];}
int pw[N], ipw[N];
int up[N], down[N], fa[K][N];
int thsh(int x, int y) {
  if(dep[x] > dep[y]) return 1ll * (up[x] + mod - up[y]) * ipw[dep[y] - 1] % mod;
  return (down[y] - 1ll * down[x] * pw[dep[y] - dep[x]] % mod + mod) % mod;
}
void dfs(int id, int ff) {
  sz[id] = 1;
  dfn[id] = ++dn;
  fa[0][id] = ff;
  dep[id] = dep[ff] + 1;
  for(pii _ : e[id]) {
    int it = _.first, c = _.second;
    if(it == ff) continue;
    fc[it] = c;
    down[it] = (1ll * down[id] * base + c) % mod;
    up[it] = (up[id] + 1ll * c * pw[dep[id] - 1]) % mod; 
    dfs(it, id);
    sz[id] += sz[it];
  }
}
vector<int> pos[N];
int len, s[N], pre[N];
int shsh(int l, int r) {return (pre[r] - 1ll * pre[l - 1] * pw[r - l + 1] % mod + mod) % mod;}
int sa[N], rk[N], ork[N], buc[N], id[N];
bool cmp(int a, int b, int w) {return ork[a] == ork[b] && ork[a + w] == ork[b + w];}
void build(int n, int *s) {
  int m = ::m + 30, p = 0;
  for(int i = 1; i <= n; i++) buc[rk[i] = s[i]]++;
  for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
  for(int i = n; i; i--) sa[buc[rk[i]]--] = i;
  for(int w = 1; ; w <<= 1, m = p, p = 0) {
    for(int i = n - w + 1; i <= n; i++) id[++p] = i;
    for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
    memset(buc, 0, sizeof(buc));
    for(int i = 1; i <= n; i++) buc[rk[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[id[i]]]--] = id[i];
    memcpy(ork, rk, sizeof(rk)), p = 0;
    for(int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i - 1], sa[i], w) ? p : ++p;
    if(p == n) break;
  }
}
ll ans[N];
int u[N], v[N], lb[N], rb[N];
vector<int> qu[N];
struct BIT {
  int c[N];
  void add(int x) {while(x <= len) c[x]++, x += x & -x;}
  int query(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}
  int query(int l, int r) {return query(r) - query(l - 1);}
} tr;
pii lcp(int x, int y, int pos) {
  auto check = [&](int a) {
    int L = abs(dep[x] - dep[a]);
    if(pos + L - 1 > len) return false;
    return thsh(x, a) == shsh(pos, pos + L - 1);
  };
  if(!isanc(x, y)) {
    int a = x;
    for(int i = lg; ~i; i--)
      if(!isanc(fa[i][a], y) && check(fa[i][a]))
        a = fa[i][a];
    if(check(fa[0][a])) a = fa[0][a];
    pos += dep[x] - dep[a]; // add this line
    if(!isanc(a, y)) return make_pair(fc[a], s[pos]);
    x = a;
  }
  if(check(y)) return make_pair(-1, s[pos + dep[y] - dep[x]]);
  for(int i = lg; ~i; i--)
    if(dep[fa[i][y]] > dep[x] && !check(fa[i][y]))
      y = fa[i][y];
  return make_pair(fc[y], s[pos + dep[y] - dep[x] - 1]);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  for(int i = pw[0] = 1; i <= n; i++) pw[i] = 1ll * pw[i - 1] * base % mod;
  ipw[0] = 1, ipw[1] = ksm(base, mod - 2);
  for(int i = 2; i <= n; i++) ipw[i] = 1ll * ipw[i - 1] * ipw[1] % mod;
  for(int i = 1; i < n; i++) {
    int u, v; char c;
    cin >> u >> v >> c;
    e[u].push_back({v, c - 'a' + 1});
    e[v].push_back({u, c - 'a' + 1});
  }
  dfs(1, 1), lg = 31 - __builtin_clz(n);
  for(int i = 1; i <= lg; i++)
    for(int j = 1; j <= n; j++)
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
  for(int i = 1; i <= m; i++) {
    string str;
    cin >> str;
    for(char it : str) s[++len] = it - 'a' + 1, pos[i].push_back(len);
    s[++len] = i + 30;
  }
  s[len + 1] = -1;
  for(int i = 1; i <= len; i++) pre[i] = (1ll * pre[i - 1] * base + s[i]) % mod;
  build(len, s);
  for(int i = 1; i <= q; i++) {
    int l, r;
    cin >> u[i] >> v[i] >> l >> r;
    if(l - 1) qu[l - 1].push_back(-i);
    qu[r].push_back(i);
  }
  for(int _ = 1; _ <= m; _++) {
    for(int it : pos[_]) tr.add(rk[it]);
    for(int it : qu[_]) {
      int id = abs(it), coef = id / it;
      if(lb[id]) {
        ans[id] += tr.query(lb[id], rb[id]) * coef;
        continue;
      }
      int l = 1, r = len + 1;
      int ql = -1, qr = -1;
      while(l < r) {
        int m = l + r >> 1;
        pii info = lcp(u[id], v[id], sa[m]);
        if(info.first == -1) r = m;
        else if(info.first > info.second) l = m + 1;
        else r = m;
      }
      ql = l;
      l = 0, r = len;
      while(l < r) {
        int m = l + r + 2 >> 1;
        pii info = lcp(u[id], v[id], sa[m]);
        if(info.first == -1) l = m;
        else if(info.first < info.second) r = m - 1;
        else l = m;
      }
      qr = r;
      lb[id] = ql, rb[id] = qr;
      ans[id] += tr.query(ql, qr) * coef;
    }
  }
  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/2
author: Alex_Wei
start coding at 11:17
finish debugging at 14:11
*/