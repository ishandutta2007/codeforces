#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int, int>> G[N];
int edge_index[N], sz[N];
long long weight[N];

void dfs(int v, int p) {
  sz[v] = 1;
  for (auto& [u, i]: G[v]) {
    if (u == p) continue;
    edge_index[u] = i;
    dfs(u, v);
    sz[v] += sz[u];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
    edges.emplace_back(u, v, w);
  }
  dfs(1, 1);

  long long cur = 0;
  const double denom = 1.0*n*(n-1)/6;
  for (int v = 1; v <= n; v++) {
    weight[v] = 1LL*sz[v]*(n-sz[v]);
    if (v > 1) cur += weight[v]*get<2>(edges[edge_index[v]]);
  }
  
  for (int i = 0; i < n-1; i++) {
    // make sure the first is the child
    if (sz[get<0>(edges[i])] > sz[get<1>(edges[i])]) {
      swap(get<0>(edges[i]), get<1>(edges[i]));
    }
  }
  
  int q;
  cin >> q;
  while (q--) {
    int r, w;
    cin >> r >> w;
    r--;
    cur -= weight[get<0>(edges[r])]*(get<2>(edges[r])-w);
    get<2>(edges[r]) = w;
    cout << cur/denom << '\n';
  }
}