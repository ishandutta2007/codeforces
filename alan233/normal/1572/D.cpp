// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
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

const int N = 20;
const int inf = 1e9;

struct E {
  int u, v, w;
} e[N * (1 << N)];
int a[1 << N], id[1 << N], ind;
int n, k, all, m, used;

struct Flow {
  struct Edge {
    int to, nxt, cap, cost;
  } edge[50005];
  int head[20005], h[20005], etot = 1;
  void add(int u, int v, int cap, int cost) {
//    assert(etot <= 50000);
    edge[++etot] = {v, head[u], cap, cost};
    head[u] = etot;
  }
  void addedge(int u, int v, int cap, int cost) {
    cost *= -1;
    add(u, v, cap, cost), add(v, u, 0, -cost);
  }
  
  int S, T, T2;
  
  int dis[20005];
  bool vis[20005];
  bool spfa(int S, int T) {
    rep(i, 1, T) dis[i] = inf, vis[i] = 0, h[i] = head[i];
    queue<int> q;
    q.push(S), dis[S] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = 0;
      for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to, cap = edge[i].cap, cost = edge[i].cost;
        if (cap && dis[v] > dis[u] + cost) {
          dis[v] = dis[u] + cost;
          if (!vis[v]) vis[v] = 1, q.push(v);
        }
      }
    }
    return dis[T] != inf;
  }
  int mf, mc;
  int dfs(int u, int T, int ans) {
    if (u == T) return ans;
    vis[u] = 1;
    int over = 0;
    for (int &i = h[u]; i; i = edge[i].nxt) {
      int v = edge[i].to, cap = edge[i].cap, cost = edge[i].cost;
      if (!vis[v] && cap && dis[v] == dis[u] + cost) {
        int go = dfs(v, T, min(ans, cap));
        ans -= go, over += go, mc += cost * go;
        edge[i].cap -= go, edge[i ^ 1].cap += go;
        if (!ans) break;
        if (!go) dis[v] = -inf;
      }
    }
    vis[u] = 0;
    return over;
  }
  pii MCMF(int S, int T) {
    mf = mc = 0;
    while (spfa(S, T)) {
      mf += dfs(S, T, 1e9);
    }
    return {mf, mc};
  }
} mcmf;
 
int main() {
  n = read(), k = read(), all = 1 << n;
#ifdef xay
  rep(i, 0, all - 1) a[i] = 1;
#else
  rep(i, 0, all - 1) a[i] = read();
#endif
  rep(i, 0, all - 1) {
    rep(j, 0, n - 1) {
      if (i >> j & 1) 
        e[++m] = {i, i ^ 1 << j, a[i] + a[i ^ 1 << j]};
    }
  }
  used = min(m, (2 * n - 1) * (k - 1) + 1);
//  used = m;
  nth_element(e + 1, e + used, e + m + 1, [&](E x, E y) {
    return x.w > y.w;
  });
  mcmf.S = 19999, mcmf.T = 20000, mcmf.T2 = 20001;
  mcmf.addedge(mcmf.T, mcmf.T2, k, 0);
  rep(i, 1, used) {
    if (__builtin_popcount(e[i].u) & 1) swap(e[i].u, e[i].v); 
    if (!id[e[i].u]) id[e[i].u] = ++ind, mcmf.addedge(mcmf.S, ind, 1, 0);
    if (!id[e[i].v]) id[e[i].v] = ++ind, mcmf.addedge(ind, mcmf.T, 1, 0);
    mcmf.addedge(id[e[i].u], id[e[i].v], 1, e[i].w);
  }
  print(-mcmf.MCMF(mcmf.S, mcmf.T2).sec, '\n');
  return 0;
}

/*
20 100
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
*/