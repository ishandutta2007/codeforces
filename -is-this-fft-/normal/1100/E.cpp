#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
vector<pair<int, int>> adj [MAX_N]; // <oth, cost>

int n;
int vis [MAX_N]; // 0 - unvisited, 1 - in sub, 2 - visited

void acyclic_dfs (int u, int c, bool &ok) {
  vis[u] = 1;
  for (auto pr : adj[u]) {
    if (pr.second >= c) {
      if (vis[pr.first] == 1) {
        ok = false;
      } else if (vis[pr.first] == 0) {
        acyclic_dfs(pr.first, c, ok);
      }
    }
  }
  vis[u] = 2;
}

bool acyclic (int c) { // is acyclic if we only consider >= c?
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      acyclic_dfs(i, c, ok);
    }
  }

  return ok;
}

void topo_dfs (int u, int c, vector<int> &ans) {
  vis[u] = 1;
  for (auto pr : adj[u]) {
    if (pr.second >= c) {
      if (!vis[pr.first]) {
        topo_dfs(pr.first, c, ans);
      }
    }
  }
  ans.push_back(u);
}

vector<int> find_topo (int c) {
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      topo_dfs(i, c, ans);
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int m;
  cin >> n >> m;

  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    edges.push_back({u, v});
  }

  if (acyclic(0)) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  
  int ans = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    if (!acyclic(ans + k)) {
      ans += k;
    }
  }
  ans++;

  vector<int> topo = find_topo(ans);
  vector<int> topopos (n + 1);
  for (int i = 0; i < (int) topo.size(); i++) {
    topopos[topo[i]] = i;
  }

  vector<int> edge_ans;
  for (int i = 0; i < (int) edges.size(); i++) {
    if (topopos[edges[i].first] < topopos[edges[i].second]) {
      edge_ans.push_back(i + 1);
    }
  }

  cout << ans - 1 << " " << (int) edge_ans.size() << '\n';
  for (int u : edge_ans) {
    cout << u << ' ';
  }
  cout << endl;
}