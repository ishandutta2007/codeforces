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

const int N = 300005;

vector<int> adj[N];
int n;
ll a[N], ans;

bool ban[N];
int maxp[N], sz[N], SUM, rt;
void getrt(int u, int fa) {
  maxp[u] = 0, sz[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa || ban[v]) continue;
    getrt(v, u);
    sz[u] += sz[v];
    ckmax(maxp[u], sz[v]);
  }
  ckmax(maxp[u], SUM - sz[u]);
  if (maxp[rt] > maxp[u]) rt = u;
}
void getsz(int u, int fa) {
  sz[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa || ban[v]) continue;
    getsz(v, u);
    sz[u] += sz[v];
  }
}

vector<int> leaf[N];
ll up[N], down[N], sum[N];
int dep[N], anc, LIM;
void dfs1(int u, int fa) {
  sum[u] = sum[fa] + a[u];
  dep[u] = dep[fa] + 1;
  ckmax(LIM, dep[u] + 1);
  up[u] = up[fa] + dep[u] * a[u];
  down[u] = down[fa] + sum[u];
  ckmax(ans, down[u]);
  ckmax(ans, up[u] + sum[u]);
//  printf("up[%d] = %lld, down[%d] = %lld\n", u, up[u], u, down[u]);
  int son = 0;
  for (auto v: adj[u]) {
    if (v == fa || ban[v]) continue;
    son++;
    dfs1(v, u);
  }
  if (!son) leaf[anc].pb(u);
}

struct LCT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  struct Func {
    ll k, b;
    ll eval(ll x) {
      return k * x + b;
    }
  } tr[N << 2];
  void build(int u, int l, int r) {
    assert(l <= r);
    tr[u].k = tr[u].b = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
  }  
  void ins(int u, int l, int r, Func f) {
    int mid = l + r >> 1;
    if (tr[u].eval(mid) < f.eval(mid)) swap(tr[u], f);
    if (l == r) return ;
    if (tr[u].k < f.k) ins(rs, mid + 1, r, f);
    else ins(ls, l, mid, f); 
  }
  ll query(int u, int l, int r, int x) {
    assert(l <= x && x <= r);
    if (l == r) return tr[u].eval(x);
    int mid = l + r >> 1;
    ll ret = tr[u].eval(x);
    if (x <= mid) ckmax(ret, query(ls, l, mid, x));
    else ckmax(ret, query(rs, mid + 1, r, x));
    return ret;
  }
} smt;

void dfz(int u) {
//  printf("now dfz = %d\n", u);
  LIM = 0;
  ban[u] = 1, dep[u] = 0, up[u] = 0, down[u] = sum[u] = a[u];
  getsz(u, 0);
  int son = 0;
  for (auto v: adj[u]) {
    if (ban[v]) continue;
    leaf[v].clear(), leaf[v].shrink_to_fit();
    anc = v;
    son++;
    dfs1(v, u);
  }
  if (!son) {
    ckmax(ans, a[u]);
    return ;
  }
  assert(LIM >= 1);
  smt.build(1, 1, LIM);
  for (auto v: adj[u]) {
    if (ban[v]) continue;
    for (auto node: leaf[v])
      ckmax(ans, smt.query(1, 1, LIM, dep[node] + 1) + down[node]);
    for (auto node: leaf[v])
      smt.ins(1, 1, LIM, {sum[node] - a[u], up[node]});
  }
//  printf("ans = %lld\n", ans);
  reverse(adj[u].begin(), adj[u].end()); //  
  smt.build(1, 1, LIM);
  for (auto v: adj[u]) {
    if (ban[v]) continue;
    for (auto node: leaf[v])
      ckmax(ans, smt.query(1, 1, LIM, dep[node] + 1) + down[node]);
    for (auto node: leaf[v])
      smt.ins(1, 1, LIM, {sum[node] - a[u], up[node]});
  }
//  printf("ans = %lld\n", ans);
  for (auto v: adj[u]) {
    if (ban[v]) continue;
    maxp[rt = 0] = n, SUM = sz[v], getrt(v, 0);
    dfz(rt);
  }
}

int main() {
  n = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  rep(i, 1, n) a[i] = read();
  maxp[rt = 0] = SUM = n, getrt(1, 0);
  dfz(rt);
  print(ans, '\n');
  return 0;
}