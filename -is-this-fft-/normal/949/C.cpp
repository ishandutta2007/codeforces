#define ran(i, a, b) for (auto i = (a); i < (b); i++)

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Graph {
  int n;
  vector<vector<int> > con;

  Graph(int nsize) {
    n = nsize;
    con.resize(n);
  }

  void add_edge(int u, int v) { con[u].push_back(v); }

  void top_dfs(int pos, vector<int> &result,
    vector<bool> &explr, vector<vector<int> > &revcon) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : revcon[pos])
      top_dfs(next, result, explr, revcon);
    result.push_back(pos);
  }

  vector<int> topsort() {
    vector<vector<int> > revcon(n);
    ran(u, 0, n) {
      for (auto v : con[u]) revcon[v].push_back(u);
    }

    vector<int> result;
    vector<bool> explr(n, false);
    ran(i, 0, n) top_dfs(i, result, explr, revcon);
    reverse(result.begin(), result.end());
    return result;
  }/*ly*/

  void dfs(
    int pos, vector<int> &result, vector<bool> &explr) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : con[pos]) dfs(next, result, explr);
    result.push_back(pos);
  }/*ry*//*lp*/
  vector<vector<int> > scc() {
    //!pause
    // tested on
    // https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-comps/practice-problems/algorithm/a-walk-to-remember-qualifier2/
    //!unpause
    vector<int> order = topsort();
    reverse(order.begin(), order.end());
    vector<bool> explr(n, false);
    vector<vector<int> > res;
    for (auto it = order.rbegin(); it != order.rend();
         ++it) {
      vector<int> comp;
      top_dfs(*it, comp, explr, con);
      sort(comp.begin(), comp.end());
      res.push_back(comp);
    }
    sort(res.begin(), res.end());
    return res;
  }/*rp*/
};
//!finish

const int MAX_N = 1e5 + 5;

int hr [MAX_N];
vector<int> adj [MAX_N];
int scc_id [MAX_N];

bool is_sink (const vector<int> &scc) {
  int id = scc[0];
  for (int u : scc) {
    for (int v : adj[u]) {
      if (scc_id[v] != id) return false;
    }
  }
  return true;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, h;
  cin >> n >> m >> h;

  for (int i = 0; i < n; i++) {
    cin >> hr[i];
  }

  Graph G (n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    if ((hr[u] + 1) % h == hr[v]) {
      adj[u].push_back(v);
      G.add_edge(u, v);
    }

    if ((hr[v] + 1) % h == hr[u]) {
      adj[v].push_back(u);
      G.add_edge(v, u);
    }
  }

  vector<vector<int>> sccs = G.scc();
  for (vector<int> scc : sccs) {
    for (int u : scc) {
      scc_id[u] = scc[0];
    }
  }

  pair<int, int> ans = make_pair(n + 1, -1);
  for (int i = 0; i < (int) sccs.size(); i++) {
    if (!sccs[i].empty() && is_sink(sccs[i])) {
      ans = min(ans, make_pair((int) sccs[i].size(), i));
    }
  }

  cout << sccs[ans.second].size() << '\n';
  for (int u : sccs[ans.second]) {
    cout << u + 1 << " ";
  }
  cout << '\n';
}