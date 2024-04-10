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

const int N = 500005;
const ll inf = 1e18;

struct Edge {
  int to, nxt, val;
} edge[N << 1];
int head[N], tot;
inline void add(int u, int v, int w) {
  edge[++tot] = {v, head[u], w};
  head[u] = tot;
}

int n, m, K, q;

ll dis[N]; int who[N];
void dijkstra() {
  #define pli pair<ll, int>
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  rep(i, 1, n) dis[i] = inf;
  rep(i, 1, K) dis[i] = 0, who[i] = i, pq.push({0, i});
  while (!pq.empty()) {
    auto [_, u] = pq.top(); pq.pop();
    if (dis[u] != _) continue;
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (dis[v] > dis[u] + edge[i].val) {
        dis[v] = dis[u] + edge[i].val;
        who[v] = who[u];
        pq.push({dis[v], v});
      }
    }
  }
}

struct node {
  int u, v; ll w;
  friend bool operator < (const node &x, const node &y) {
    return x.w < y.w;
  }
};
vector<node> edg;
int f[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y) { f[find(x)] = find(y); }

vector<pair<int, ll>> adj[N];
int dep[N], tmpf[N][20];
ll tmpg[N][20];
void dfs(int u, int fa) {
  for (int i = 1; i < 20; i++) {
    tmpf[u][i] = tmpf[tmpf[u][i - 1]][i - 1];
    tmpg[u][i] = max(tmpg[u][i - 1], tmpg[tmpf[u][i - 1]][i - 1]);
  }
  // printf("dfs u = %d, fa = %d\n", u, fa);
  dep[u] = dep[fa] + 1;
  for (auto [v, w]: adj[u]) {
    if (v == fa) continue;
    tmpf[v][0] = u, tmpg[v][0] = w;
    dfs(v, u);
  }
}
ll calc(int u, int v) {
  // printf("calc #1 %d %d\n", u, v);
  ll res = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[tmpf[u][i]] >= dep[v]) {
      ckmax(res, tmpg[u][i]);
      u = tmpf[u][i];
    }
  }
  // printf("calc #2 %d %d, res = %lld\n", u, v, res);
  if (u == v) return res;
  for (int i = 19; i >= 0; i--) {
    if (tmpf[u][i] != tmpf[v][i]) {
      ckmax(res, max(tmpg[u][i], tmpg[v][i]));
      u = tmpf[u][i], v = tmpf[v][i];
    }
  }
  ckmax(res, max(tmpg[u][0], tmpg[v][0]));
  return res;
}


int main() {
  n = read(), m = read(), K = read(), q = read();
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    add(u, v, w), add(v, u, w);
  }
  dijkstra();
  for (int i = 1; i <= tot; i += 2) {
    int u = edge[i].to, v = edge[i + 1].to, w = edge[i].val;
    edg.pb({who[u], who[v], w + dis[u] + dis[v]});
  }
  sort(edg.begin(), edg.end());
  iota(f + 1, f + K + 1, 1);
  for (auto [u, v, w]: edg) {
    // printf("edg %d %d, val = %lld\n", u, v, w);
    if (find(u) != find(v)) {
      adj[u].pb({v, w});
      adj[v].pb({u, w});
      merge(u, v);
    }
  }
  dfs(1, 0);
  while (q--) {
    int x = read(), y = read();
    print(calc(x, y), '\n');
  }
  return 0;
}