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

const int N = 300005;

int ans;

vector<int> adj[N];
int f[N][20], n, q;

int in[N], out[N], dtot, dep[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  f[u][0] = fa, in[u] = ++dtot;
  for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (auto v: adj[u]) dfs1(v, u);
  out[u] = dtot;
}
int jump(int u, int kth) {
  for (int i = 19; i >= 0; i--)
    if (kth >> i & 1)
      u = f[u][i];
  return u;
}

int id[N];
vector<int> zz[N];

struct Fen {
  int c[N];
  void add(int x, int dlt) {
    while (x <= n) c[x] += dlt, x += x & -x;
  }  
  int qry(int x) {
    int ret = 0;
    while (x) ret += c[x], x ^= x & -x;
    return ret;
  }
  int qry(int l, int r) {
    return qry(r) - qry(l - 1);
  } 
  int qtree(int u) {
    return qry(in[u], out[u]);
  }
} bit;

int main() {
  n = read(), q = read();
  rep(i, 2, n) {
    int fa = read();
    adj[fa].pb(i);
  }
  dfs1(1, 0);
  vector<pii> cross_edge;
  while (q--) {
    int u = read(), v = read();
    if (dep[u] > dep[v]) swap(u, v);
    if (dep[u] + 1 == dep[v] && f[v][0] == u) {
      puts("-1");
      return 0; 
    }
    zz[u].pb(v);
  }
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [&](int x, int y) {
    return dep[x] > dep[y];
  });
  for (int _ = 1; _ <= n; _++) {
    int u = id[_];
    for (auto v: zz[u]) {
      int sonu = jump(v, dep[v] - dep[u] - 1);
      if (f[sonu][0] != u) { //  
        cross_edge.pb({u, v});
        continue;
      }
      int num = bit.qtree(sonu) - bit.qtree(v);
      if (!num) {
        ans++;
        bit.add(in[sonu], 1);
      }
    }
  }
  for (auto it: cross_edge) {
    int x = it.fir, y = it.sec;
    int num = bit.qtree(x) + bit.qtree(y);
    if (num == ans) {
      ans++;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}