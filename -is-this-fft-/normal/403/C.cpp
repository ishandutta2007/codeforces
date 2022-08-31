#include <iostream>
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

  void add_edge (int u, int v) {
    adj[u].push_back(v);
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
      if (!comp.empty()) {
        res.push_back(comp);
      }
    }
    return res;
  }
};

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  Graph G (n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      if (x > 0) {
        G.add_edge(i, j);
      }
    }
  }

  auto scc = G.scc();
  if ((int) scc.size() == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}