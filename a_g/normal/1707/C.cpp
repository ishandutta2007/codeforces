#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const int K = 16;
vector<int> G[N];
int tin[N], tout[N], par[N][K], s[2*N];
int timer = 0;

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
  tin[v] = timer++;
  par[v][0] = p;
  for (int i = 1; i < K; i++) {
    par[v][i] = par[par[v][i-1]][i-1];
  }
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  tout[v] = timer++;
}

void add_subtree(int v, int k) {
  s[tin[v]] += k;
  s[tout[v]] -= k;
}

bool is_ancestor(int u, int v) {
  return tin[u] < tin[v] && tout[u] > tout[v];
}

void add(int u, int v) {
  // add 1 to the subtree of v when rooted at u
  if (is_ancestor(v, u)) {
    add_subtree(1, 1);
    for (int i = K-1; i >= 0; i--) {
      if (is_ancestor(v, par[u][i])) {
        u = par[u][i];
      }
    }
    add_subtree(u, -1);
  }
  else {
    add_subtree(v, 1);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu D(n+1);
  vector<pair<int, int>> bad_edges;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (!D.join(u, v)) {
      bad_edges.emplace_back(u, v);
    }
    else {
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }
  dfs(1, 0);

  for (pair<int, int>& p: bad_edges) {
    add(p.first, p.second);
    add(p.second, p.first);
  }
  for (int i = 1; i < 2*N; i++) {
    s[i] += s[i-1];
  }

  for (int v = 1; v <= n; v++) {
    cout << (s[tin[v]] == (int)bad_edges.size());
  }
  cout << '\n';
}