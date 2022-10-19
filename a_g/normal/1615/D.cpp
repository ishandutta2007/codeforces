#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+2;
vector<pair<int, int>> adj[maxn];
vector<tuple<int, int, int>> ans;
vector<pair<int, int>> missing_edges;
int label[maxn];
bool good;

void dfs(int v, int k) {
  label[v] = k;
  for (pair<int, int> edge: adj[v]) {
    int u = edge.first;
    int l = edge.second^label[v];
    if (label[u] == -1) {
      dfs(u, l);
    }
    else {
      if (label[u] != l) good = 0;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    good = 1;
    missing_edges.clear();
    ans.clear();
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      label[i] = -1;
    }
    for (int i = 0; i < n-1; i++) {
      int x, y, v;
      cin >> x >> y >> v;
      if (v != -1) {
        ans.push_back({x, y, v});
        int u = (v == -1 ? -1 : __builtin_popcount(v)&1);
        adj[x].push_back({y, u});
        adj[y].push_back({x, u});
      }
      else {
        missing_edges.push_back({x, y});
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      adj[a].push_back({b, p});
      adj[b].push_back({a, p});
    }

    for (int i = 1; i <= n; i++) {
      if (label[i] == -1) dfs(i, 0);
    }
    if (good) {
      cout << "YES\n";
      for (pair<int, int> e: missing_edges) {
        int u = e.first;
        int v = e.second;
        ans.push_back({u, v, label[u]^label[v]});
      }
      for (tuple<int, int, int> t: ans) {
        int x, y, v;
        tie(x, y, v) = t;
        cout << x << " " << y << " " << v << '\n';
      }
    }
    else {
      cout << "NO\n";
    }
  }
}