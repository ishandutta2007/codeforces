#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    ans.resize(m);
    for (int i = 0; i < m; ++i) {
      int v, u;
      cin >> v >> u;
      g[--v].push_back({--u, i});
      g[u].push_back({v, i});
      edges.push_back({v, u});
    }

    used.resize(n, 0);
    parent.resize(n, -1);
    height.resize(n, -1);
    dfs(0, 0);

    set<pair<int, int>> vs;
    for (auto i : ids) {
      int v = edges[i].first;
      vs.insert({height[v], v});
      v = edges[i].second;
      vs.insert({height[v], v});
    }

    if (ids.size() < 3 || vs.size() > 3) {
      for (int i = 0; i < m; ++i) {
        cout << ans[i];
      }
      cout << "\n";
      return;
    }
    vector<pair<int, int>> b{vs.begin(), vs.end()};
    flip(b[2].second, parent[b[2].second]);
    flip(b[2].second, b[0].second);

    for (int i = 0; i < m; ++i) {
      cout << ans[i];
    }
    cout << "\n";
  }

private:
  vector<vector<pair<int, int>>> g;
  vector<int> ans;
  vector<int> used;
  vector<int> ids;
  vector<pair<int, int>> edges;
  vector<int> parent;
  vector<int> height;

  void flip(int v, int u) {
    for (int i = 0; i < (int)ans.size(); ++i) {
      if ((edges[i].first == u && edges[i].second == v) || (edges[i].first == v && edges[i].second == u)) {
        ans[i] = 1 - ans[i];
      }
    }
  }

  void dfs(int v, int h, int par = -1) {
    parent[v] = par;
    height[v] = h;
    used[v] = true;
    for (auto [u, i] : g[v]) {
      if (used[u]) {
        if (par != u) {
          ans[i] = 1;
          ids.push_back(i);
        }
      } else {
        dfs(u, h + 1, v);
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solver{}.solve();
  }
}