#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph {
  int n;
  vector<vector<int>> adj;

  void top_dfs (int pos, vector<int> &result,
                vector<bool> &explr, vector<vector<int>> &revadj) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : revadj[pos]) {
      top_dfs(next, result, explr, revadj);
    }
    result.push_back(pos);
  }
  
public:
  Graph (int _n) : n(_n), adj(_n, vector<int> (0)) {}

  vector<pair<int, int>> edges;
  
  void add_edge (int u, int v) {
    adj[u].push_back(v);
    edges.push_back(make_pair(u, v));
  }

  vector<int> topsort () {
    vector<vector<int>> revadj (n);
    for (int u = 0; u < n; u++) {
      for (auto v : adj[u]) {
        revadj[v].push_back(u);
      }
    }

    vector<int> result;
    vector<bool> explr (n, false);
    for (int i = 0; i < n; i++) {
      top_dfs(i, result, explr, revadj);
    }
    reverse(result.begin(), result.end());
    return result;
  }
  
  vector<vector<int>> scc () {
    vector<int> order = topsort();
    reverse(order.begin(), order.end());
    vector<bool> explr (n, false);
    vector<vector<int>> res;
    for (auto it = order.rbegin(); it != order.rend();
         ++it) {
      vector<int> comp;
      top_dfs(*it, comp, explr, adj);
      sort(comp.begin(), comp.end());
      if (!comp.empty()) res.push_back(comp);
    }
    sort(res.begin(), res.end());
    return res;
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid (n, vector<int> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;

      if (c != '.') {
        grid[i][j] = 1;
      }
    }
  }

  vector<int> target (m);
  for (int i = 0; i < m; i++) {
    cin >> target[i];
  }

  vector<pair<int, int>> pos;
  vector<map<int, int>> block_ids (m);
  for (int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (grid[i][j]) {
        int id = pos.size();
        
        block_ids[j][i] = id;
        pos.push_back(make_pair(i, j));
      }
    }
  }

  int vc = pos.size();
  Graph G (vc);
  for (auto pr : pos) {
    int row = pr.first;
    int col = pr.second;

    auto it = block_ids[col].find(row);
    int id = it->second;
    
    if (it != block_ids[col].begin()) {
      auto prv = prev(it);
      if (prv->first == row - 1) {
        G.add_edge(id, prv->second);
      }
    }

    auto nxt = block_ids[col].upper_bound(row);
    if (nxt != block_ids[col].end()) {
      G.add_edge(id, nxt->second);
    }

    if (col != 0) {
      auto lft = block_ids[col - 1].lower_bound(row);
      if (lft != block_ids[col - 1].end()) {
        G.add_edge(id, lft->second);
      }
    }

    if (col != m - 1) {
      auto rgt = block_ids[col + 1].lower_bound(row);
      if (rgt != block_ids[col + 1].end()) {
        G.add_edge(id, rgt->second);
      }
    }
  }

  auto scc = G.scc();
  
  vector<int> comp (vc);
  for (int i = 0; i < (int) scc.size(); i++) {
    for (int u : scc[i]) {
      comp[u] = i;
    }
  }

  vector<int> indeg (scc.size(), 0);
  for (auto e : G.edges) {
    if (comp[e.first] != comp[e.second]) {
      indeg[comp[e.second]]++;
    }
  }

  int ans = 0;
  for (int u : indeg) {
    if (u == 0) ans++;
  }

  cout << ans << endl;
}