#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
vector<pair<int, int>> G[N];
long long a[N];
int x;
vector<int> late_roads;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

void dfs(int v, int p) {
  for (auto& [u, i]: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    if (a[v]+a[u] >= x) {
      cout << i << '\n';
      a[v] += a[u]-x;
    }
    else {
      late_roads.emplace_back(i);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++)  cin >> a[i]; 
  if (accumulate(a, a+n, 0LL) < 1LL*x*(n-1)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";

  dsu D(n);
  vector<tuple<int, int, int>> edges;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (D.join(u, v)) {
      edges.emplace_back(u, v, i);
      G[u].emplace_back(v, i);
      G[v].emplace_back(u, i);
    }
  }
  dfs(0, -1);
  reverse(late_roads.begin(), late_roads.end());
  for (int i: late_roads) {
    cout << i << '\n';
  }
}