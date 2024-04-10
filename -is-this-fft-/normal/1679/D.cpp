#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Graph {
  int n;
  vector<vector<int>> adj;

  vector<int> vis;
  bool cyc_dfs (int u) {
    vis[u] = 1;
    for (int nxt : adj[u]) {
      if (vis[nxt] == 1) {
        return true;
      }

      if (vis[nxt] == 0) {
        bool found = cyc_dfs(nxt);
        if (found) {
          return true;
        }
      }
    }
    vis[u] = 2;
    return false;
  }

  vector<int> dp;
  int calc_dp (int u) {
    if (vis[u]) {
      return dp[u];
    }

    dp[u] = 0;
    for (int nxt : adj[u]) {
      dp[u] = max(dp[u], 1 + calc_dp(nxt));
    }

    vis[u] = 1;
    return dp[u];
  }
  
public:
  Graph (int _n) : n(_n), adj(_n, vector<int> (0)) {
  }

  void add_edge (int u, int v) {
    adj[u].push_back(v);
  }

  bool has_path_length (ll k) {
    vis = vector<int> (n, 0);
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) {
        if (cyc_dfs(i)) {
          return true;
        }
      }
    }

    vis = vector<int> (n, 0);
    dp = vector<int> (n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, calc_dp(i));
    }

    return (ll) ans >= k - 1;
  }
};

Graph build_graph (const vector<int> &arr, const vector<pair<int, int>> &edges, int cap) {
  Graph G ((int) arr.size());
  for (auto e : edges) {
    if (arr[e.first] <= cap && arr[e.second] <= cap) {
      G.add_edge(e.first, e.second);
    }
  }
  return G;
}

const int MAX_A = 1e9 + 5;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  ll K;
  cin >> n >> m >> K;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  vector<pair<int, int>> edges (m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--; edges[i].second--;
  }

  if (K == 1) {
    int mn = arr[0];
    for (int i = 1; i < n; i++) {
      mn = min(mn, arr[i]);
    }
    cout << mn << endl;
    return 0;
  }

  int ans = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    auto G = build_graph(arr, edges, ans + k);
    if (!G.has_path_length(K)) {
      ans += k;
    }
  }

  if (ans > MAX_A) {
    cout << -1 << '\n';
    return 0;
  }
  
  cout << ans + 1 << '\n';
}