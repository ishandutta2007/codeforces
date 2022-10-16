// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

int a[N], n, m;
vector<int> adj[N];
int dep[N], f[N][20], dfn[N], sz[N], dad[N], dtot;

inline int calc(int x, int y) {
  return max(abs(a[x] + a[y]), abs(a[x] - a[y]));
}

void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  dfn[u] = ++dtot, sz[u] = 1;
  dad[u] = fa, f[u][0] = fa;
  rep(i, 1, 19) f[u][i] = f[f[u][i - 1]][i - 1];
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    sz[u] += sz[v];
  }
}
inline int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  per(i, 19, 0) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  if (u == v) return u;
  per(i, 19, 0) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}

struct Fenwick {
  ll c[N];
  void add(int x, int dlt) {
    while (x <= n) {
      c[x] += dlt;
      x += x & -x;
    }
  }
  void add(int l, int r, int dlt) {
    add(l, dlt), add(r + 1, -dlt);
  }
  ll qry(int x) {
    ll ret = 0;
    while (x) {
      ret += c[x];
      x ^= x & -x;
    }
    return ret;
  }
} tr;

int main() {
  n = read(), m = read();
  rep(i, 1, n) a[i] = abs(read());
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  } 
  dfs1(1, 0);
  rep(u, 1, n) {
    tr.add(dfn[u], dfn[u] + sz[u] - 1, a[u]);
  }
  while (m--) {
    int opt = read(), u = read(), v = read();
    if (opt == 1) {
      v = abs(v);
      tr.add(dfn[u], dfn[u] + sz[u] - 1, v - a[u]);
      a[u] = v;
    } else {
      int lca = LCA(u, v);
      print(2ll * (tr.qry(dfn[u]) + tr.qry(dfn[v]) - tr.qry(dfn[lca]) - tr.qry(dfn[dad[lca]])) - a[u] - a[v], '\n');
    }
  }
  return 0;
}