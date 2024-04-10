#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
// using lll = __int128;
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
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 4e5 + 5;
constexpr int S = 26;
bool DEBUG;
namespace SA {
  int sa[N >> 1], rk[N >> 1], ork[N >> 1], buc[N >> 1], id[N >> 1];
  int n, lg[N >> 1], mi[19][N >> 1];
  bool cmp(int a, int b, int w) {
    return ork[a] == ork[b] && ork[a + w] == ork[b + w];
  }
  void build(int _n, char *s) {
    n = _n;
    int m = 1 << 7, p = 0;
    for(int i = 1; i <= n; i++) buc[rk[i] = s[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[i]]--] = i;
    for(int w = 1; ; w <<= 1, m = p, p = 0) {
      for(int i = n - w + 1; i <= n; i++) id[++p] = i;
      for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
      memcpy(ork, rk, sizeof(rk));
      memset(buc, 0, sizeof(buc));
      p = 0;
      for(int i = 1; i <= n; i++) buc[rk[i]]++;
      for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
      for(int i = n; i; i--) sa[buc[rk[id[i]]]--] = id[i];
      for(int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i - 1], sa[i], w) ? p : ++p;
      if(p == n) break;
    }
    for(int i = 1, k = 0; i <= n; i++) {
      if(k) k--;
      while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
      mi[0][rk[i]] = k;
    }
    for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for(int i = 1; i <= lg[n]; i++)
      for(int j = 1; j + (1 << i) - 1 <= n; j++)
        mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  }
  int lcp(int i, int j) {
    if(i == j) return n - i + 1;
    if((i = rk[i]) > (j = rk[j])) swap(i, j);
    int d = lg[j - i++];
    return min(mi[d][i], mi[d][j - (1 << d) + 1]);
  }
  int lcp(int a, int b, int c, int d) {
    return min(lcp(a, c), min(b - a, d - c) + 1);
  }
}
namespace SAM {
  int cnt = 1, las = 1, s[N >> 1];
  int son[N][S], fa[N], len[N], ed[N];
  int edp[N >> 1], anc[19][N];
  void ins(int it) {
    int p = las, cur = ++cnt;
    ed[cur] = len[cur] = len[p] + 1, edp[len[cur]] = cur, las = cur;
    while(!son[p][it]) son[p][it] = cur, p = fa[p];
    if(!p) return fa[cur] = 1, void();
    int q = son[p][it];
    if(len[p] + 1 == len[q]) return fa[cur] = q, void();
    int cl = ++cnt;
    memcpy(son[cl], son[q], S << 2);
    len[cl] = len[p] + 1, fa[cl] = fa[q];
    fa[q] = fa[cur] = cl, ed[cl] = ed[q];
    while(son[p][it] == q) son[p][it] = cl, p = fa[p];
  }
  ll f[N], g[N];
  vector<int> e[N], re[N];
  bool vis[N], oc[N];
  int dn, nxt[N], dfn[N], rev[N], top[N], bot[N];
  void calcf(int id) {
    if(vis[id]) return;
    vis[id] = f[id] = 1;
    for(int it : e[id]) calcf(it), f[id] += f[it];
  }
  void calcg(int id) {
    if(vis[id]) return;
    vis[id] = 1;
    for(int it : re[id]) calcg(it), g[id] += g[it];
  }
  void dfs(int id, int tp) {
    dfn[id] = ++dn, rev[dn] = id, top[id] = tp, bot[id] = id;
    if(nxt[id]) dfs(nxt[id], tp), bot[id] = bot[nxt[id]];
    for(int it : e[id]) if(!dfn[it] && !oc[it]) dfs(it, it);
  }
  void build(int n, char *s) {
    for(int i = 1; i <= n; i++) ins(SAM::s[i] = s[i] - 'a');
    for(int i = 1; i <= cnt; i++)
      for(int j = 0; j < S; j++)
        if(son[i][j])
          e[i].push_back(son[i][j]), re[son[i][j]].push_back(i);
    calcf(1), memset(vis, 0, sizeof(vis)), g[1] = 1;
    for(int i = 1; i <= cnt; i++) calcg(i);
    for(int i = 1; i <= cnt; i++)
      for(int it : e[i])
        if(g[i] * 2 > g[it] && f[it] * 2 > f[i])
          nxt[i] = it, oc[it] = 1;
    dfs(1, 1);
    for(int i = 1; i <= cnt; i++) anc[0][i] = fa[i];
    for(int i = 1; i < 19; i++)
      for(int j = 1; j <= cnt; j++)
        anc[i][j] = anc[i - 1][anc[i - 1][j]];
  }
  int locate(int l, int r) {
    int L = r - l + 1, p = edp[r];
    for(int i = 18; ~i; i--) if(len[anc[i][p]] >= L) p = anc[i][p];
    return p;
  }
  vector<pii> partition(int l, int r) {
    vector<pii> I;
    int cur = 1;
    while(l <= r) {
      cur = son[cur][s[l++]];
      int bt = bot[cur], R = ed[bt], L = ed[bt] - (dfn[bt] - dfn[cur]) + 1;
      int ext = l > r ? 0 : SA::lcp(l, r, L, R);
      I.push_back({dfn[cur], dfn[cur] + ext});
      cur = rev[dfn[cur] + ext], l += ext;
    }
    return I;
  }
}

struct dat {
  int cnt;
  ll sind, slen;
  dat operator + (const dat &x) const {return {cnt + x.cnt, sind + x.sind, slen + x.slen};}
} val[N << 2];
void modify(int l, int r, int p, int x, dat v) {
  val[x] = val[x] + v;
  if(l == r) return;
  int m = l + r >> 1;
  if(p <= m) modify(l, m, p, x << 1, v);
  else modify(m + 1, r, p, x << 1 | 1, v);
}
dat query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  dat ans = {0, 0, 0};
  if(ql <= m) ans = query(l, m, ql, qr, x << 1);
  if(m < qr) ans = ans + query(m + 1, r, ql, qr, x << 1 | 1);
  return ans;
}

int n, dn, q, cnt;
int fa[N], sz[N], dep[N], son[N];
int rev[N], dfn[N], top[N];
vector<int> e[N];
char s[N >> 1];
void dfs1(int id) {
  sz[id] = 1, dep[id] = dep[fa[id]] + 1;
  for(int it : e[id]) {
    dfs1(it), sz[id] += sz[it];
    if(sz[son[id]] < sz[it]) son[id] = it;
  }
}
void dfs2(int id, int tp) {
  top[id] = tp, dfn[id] = ++dn, rev[dn] = id;
  if(son[id]) dfs2(son[id], tp);
  for(int it : e[id]) if(it != fa[id] && it != son[id]) dfs2(it, it);
}

struct BIT {
  ll c[N], c2[N], sum[N];
  void init() {
    for(int i = 1; i <= dn; i++) {
      int id = rev[i];
      sum[i] = sum[i - 1] + SAM::len[id] - SAM::len[fa[id]];
    }
  }
  void add(int x, int v) {
    ll xv = v * sum[x - 1];
    while(x <= dn) c[x] += v, c2[x] += xv, x += x & -x;
  }
  void add(int l, int r, int v) {add(l, v), add(r + 1, -v);}
  ll query(int x) {
    ll s = 0, s2 = 0, v = x;
    while(x) s += c[x], s2 += c2[x], x -= x & -x;
    return sum[v] * s - s2;
  }
  ll query(int l, int r) {return query(r) - query(l - 1);}
} tr;

ll ans[N >> 1];
pair<int, pii> buc[N * 50];
void modify(int x) {
  while(x) tr.add(dfn[top[x]], dfn[x], 1), x = fa[top[x]];
}
ll query(int x) {
  ll s = 0;
  while(x) s += tr.query(dfn[top[x]], dfn[x]), x = fa[top[x]];
  return s;
}

struct que {int id, l, r;};
vector<que> qu[N];
void dfs3(int id) {
  modify(1, SAM::cnt, SAM::dfn[id], 1, {1, SAM::dfn[id], SAM::len[id]});
  for(que _ : qu[id]) {
    int i = _.id, l = _.l, r = _.r, acc = 1;
    auto I = SAM::partition(l, r);
    for(pii it : I) {
      dat res = query(1, dn, it.first, it.second, 1);
      ans[i] += 1ll * res.cnt * (acc - it.first) + res.sind - res.slen;
      if(!DEBUG) buc[++cnt] = {it.first - 1, {-i, id}};
      if(!DEBUG) buc[++cnt] = {it.second, {i, id}};
      acc += it.second - it.first + 1;
    }
  }
  for(int it : e[id]) dfs3(it);
  modify(1, SAM::cnt, SAM::dfn[id], 1, {-1, -SAM::dfn[id], -SAM::len[id]});
}

bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> s + 1 >> q, n = strlen(s + 1);
  reverse(s + 1, s + n + 1);
  SA::build(n, s), SAM::build(n, s);
  for(int i = 2; i <= SAM::cnt; i++) e[fa[i] = SAM::fa[i]].push_back(i);
  dfs1(1), dfs2(1, 1), tr.init();
  for(int i = 1; i <= q; i++) {
    int r = n - read() + 1, l = n - read() + 1;
    int pos = SAM::locate(l, r);
    qu[pos].push_back({i, l, r});
  }
  dfs3(1), sort(buc + 1, buc + cnt + 1);
  for(int i = 1, p = 1; i <= dn; i++) {
    modify(SAM::rev[i]);
    while(buc[p].first == i) {
      pii it = buc[p].second;
      int id = abs(it.first), c = it.first / id;
      ans[id] += query(it.second) * c, p++;
    }
  }
  for(int i = 1; i <= q; i++) print(ans[i]), putchar('\n');
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/29
author: Alex_Wei
start coding at 9:15
finish debugging at 13:22
*/