#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace TGraph {
  const int MAX_V = 1e6 + 5;

  vector<int> adj [MAX_V];
  vector<int> cur_vtx;
  
  int _age [MAX_V];
  int cur_age;

  int _sgn [MAX_V];
  int &sgn (int u) {
    if (_age[u] != cur_age) {
      _sgn[u] = 0;
      _age[u] = cur_age;
    }
    return _sgn[u];
  }
  
  void add_edge (int u, int v) {
    if (adj[u].empty()) cur_vtx.push_back(u);
    adj[u].push_back(v);
    if (adj[v].empty()) cur_vtx.push_back(v);
    adj[v].push_back(u);
  }

  void dfs (int u, int s, bool &ok) {
    sgn(u) = s;
    for (int nxt : adj[u]) {
      if (sgn(nxt) == sgn(u)) {
        ok = false;
      } else if (sgn(nxt) == 0) {
        dfs(nxt, -s, ok);
      }
    }
  }

  void reset () {
    cur_age++;
    for (int u : cur_vtx) {
      adj[u].clear();
    }
    cur_vtx.clear();
  }
  
  bool check_and_reset () {
    bool ok = true;
    for (int u : cur_vtx) {
      if (sgn(u) == 0) {
        dfs(u, 1, ok);
      }
    }
    reset();
    return ok;
  }
  
  int idx (int comp, int sgn) {
    return 2 * comp + max(0, sgn);
  }
}

typedef long long ll;

const int MAX_N = 5e5 + 5;

int color [MAX_N];
int sgn [MAX_N];
int is_bi [MAX_N];
int comp [MAX_N];
vector<int> adj [MAX_N];

void dfs (int u, int s, int c) {
  sgn[u] = s;
  comp[u] = c;
  for (int nxt : adj[u]) {
    if (color[nxt] == color[u]) {
      if (sgn[nxt] == sgn[u]) {
        is_bi[color[u]] = false;
      } else if (sgn[nxt] == 0) {
        dfs(nxt, -sgn[u], comp[u]);
      }
    }
  }
}

pair<int, int> key (pair<int, int> pr) {
  return make_pair(min(color[pr.first], color[pr.second]),
                   max(color[pr.first], color[pr.second]));
}

bool is_bi_key (pair<int, int> pr) {
  return is_bi[color[pr.first]] && is_bi[color[pr.second]];
}

bool bykey (pair<int, int> p, pair<int, int> q) {
  return key(p) < key(q);
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, K;
  cin >> n >> m >> K;

  for (int i = 1; i <= n; i++) {
    cin >> color[i];
  }

  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back(make_pair(u, v));
  }

  for (int i = 1; i <= K; i++) {
    is_bi[i] = true;
  }

  int compc = 0;
  for (int i = 1; i <= n; i++) {
    if (sgn[i] == 0) {
      compc++;
      dfs(i, 1, compc);
    }
  }

  ll bic = 0;
  for (int i = 1; i <= K; i++) {
    if (is_bi[i]) {
      bic++;
    }
  }

  sort(edges.begin(), edges.end(), bykey);
  vector<vector<pair<int, int>>> blocks;
  for (int i = 0; i < (int) edges.size(); i++) {
    if (i == 0 || key(edges[i]) != key(edges[i - 1])) {
      blocks.push_back(vector<pair<int, int>> (0));
    }
    blocks.back().push_back(edges[i]);
  }

  ll ans = (bic * (bic - 1)) / 2;
  for (auto block : blocks) {
    if (!is_bi_key(block[0])) {
      continue;
    }

    if (color[block[0].first] == color[block[0].second]) {
      continue;
    }

    for (auto pr : block) {
      TGraph::add_edge(TGraph::idx(comp[pr.first], sgn[pr.first]),
                       TGraph::idx(comp[pr.second], sgn[pr.second]));
      TGraph::add_edge(TGraph::idx(comp[pr.first], 1),
                       TGraph::idx(comp[pr.first], -1));
      TGraph::add_edge(TGraph::idx(comp[pr.second], 1),
                       TGraph::idx(comp[pr.second], -1));
    }

    if (!TGraph::check_and_reset()) {
      ans--;
    }
  }

  cout << ans << endl;
}