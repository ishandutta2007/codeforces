#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// typedef __int128 lll;

const int N = 505;
const int M = 200010;
const ll INF = 1e18 + 5;

inline bool good (ll x_1, ll y_1, ll x_2, ll y_2, ll x_3, ll y_3) {
  return x_1 * y_2 + x_2 * y_3 + x_3 * y_1 >= y_1 * x_2 + y_2 * x_3 + y_3 * x_1;
}

bitset <M> done; 
ll d[N][N], W[M];
vector <int> g[N];
int n, m, U[M], V[M], id[N], par[N];
ll ed, far, global = LLONG_MAX, dist[N];

inline int find (int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

inline void unite (int u, int v) {
  if (find(u) == find(v)) return;
  if (rand() & 1) swap(u, v);
  par[find(u)] = find(v);
  if (u > v) swap(u, v);
  printf("%d %d\n", u, v);
}

int main() {
  cin >> n >> m;
  memset(d, 63, sizeof d);
  for (int i = 1; i <= n; ++i) {
    d[i][i] = 0, id[i] = par[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %lld", U + i, V + i, W + i);
    W[i] <<= 1LL;
    int u = U[i], v = V[i], w = W[i];
    d[u][v] = d[v][u] = w;
    g[u].emplace_back(i), g[v].emplace_back(i);
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int u = 1; u <= n; ++u) {
    sort(id + 1, id + n + 1, [&] (int i, int j) {return d[u][i] > d[u][j];});
    for (int e : g[u]) if (!done[e]) {
      done[e] = 1;
      int v = U[e] ^ u ^ V[e]; ll w = W[e];
      // cout << "-----\n";
      // for (int w : st) cout << d[u][w] << " " << d[v][w] << endl;
      ll opt = 0, minVal = d[u][id[1]];
      int last = id[1];
      for (int it = 2; it <= n; ++it) {
        int i = id[it];
        if (d[v][i] <= d[v][last]) continue; 
        ll curX = (w - d[u][i] + d[v][last]) / 2, curY = (w + d[u][i] + d[v][last]) / 2;
        if (minVal > curY) minVal = curY, opt = curX; last = i;
      }
      if (minVal > d[v][last]) minVal = d[v][last], opt = w;
      // cout << u << " " << v << " " << opt << " " << minVal << endl;
      // return 0;
      if (minVal < global) global = minVal, ed = e, far = opt;
    }
  }
  ++n;
  ++m, U[m] = U[ed], V[m] = n, W[m] = far, g[U[m]].emplace_back(m), g[V[m]].emplace_back(m);
  ++m, U[m] = V[ed], V[m] = n, W[m] = W[ed] - far, g[U[m]].emplace_back(m), g[V[m]].emplace_back(m);
  priority_queue <pair <ll, int>> pq;
  pq.emplace(0, n);
  for (int i = 1; i < n; ++i) dist[i] = INF;
  while (!pq.empty()) {
    int u = pq.top().second; pq.pop();
    for (int e : g[u]) if (e ^ ed) {
      int v = U[e] ^ u ^ V[e]; ll w = W[e];
      if (dist[v] > dist[u] + w) dist[v] = dist[u] + w, pq.emplace(-dist[v], v);
    }
  }
  printf("%0.5f\n", (double) global / 2.0);
  // printf("%lld\n", global);
  // unite(U[ed], V[ed]);
  // for (int i = 1; i <= m - 2; ++i) {
  //   if (i == ed) continue;
  //   int u = U[i], v = V[i]; ll w = W[i];
  //   if (dist[u] > dist[v]) swap(u, v);
  //   if (dist[u] + w == dist[v]) unite(u, v);
  // }
  return 0;
}