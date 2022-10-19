#include <bits/stdc++.h>
using namespace std;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      ranks.resize(n, 0);
    }
    int root(int u) {
      if (parents[u] == u) return u;
      parents[u] = root(parents[u]);
      return parents[u];
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (ranks[a] > ranks[b]) swap(a, b);
      // b has higher rank
      parents[a] = b;
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};

vector<vector<int>> nbrs;
vector<int> path;

bool getpath(int u, int v, int p) {
  if (u == v) {
    path.push_back(u);
    return 1;
  }
  for (int w: nbrs[u]) {
    if (w != p && getpath(w, v, u)) {
      path.push_back(u);
      return 1;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m, n;
  cin >> n >> m;
  nbrs.resize(n);
  dsu d(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (d.join(u, v)) {
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }
  }

  int Q;
  cin >> Q;
  vector<pair<int, int>> queries(Q);

  vector<bool> odd(n, 0);
  for (int i = 0; i < Q; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    queries[i] = {u, v};
    odd[u] = 1-odd[u];
    odd[v] = 1-odd[v];
  }
  int oddcount = 0;
  for (bool b: odd) {
    oddcount += b;
  }
  if (oddcount > 0) {
    cout << "NO" << '\n';
    cout << oddcount/2 << '\n';
    return 0;
  }
  cout << "YES" << '\n';

  for (pair<int, int> p: queries) {
    int u = p.first;
    int v = p.second;
    path.clear();
    getpath(v, u, v);
    cout << path.size() << '\n';
    for (int v: path) cout << v+1 << ' ';
    cout << '\n';
  }
}