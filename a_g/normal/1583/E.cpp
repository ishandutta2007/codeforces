#include <bits/stdc++.h>
#define ll long long
using namespace std;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> sizes; //subtree size, maintained at root
    dsu (int n) {
      parents.resize(n);
      for (int i = 0; i < n; i++) {
        parents[i] = i;
      }
      ranks.resize(n, 0);
      sizes.resize(n, 1);
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
      int size = sizes[a] + sizes[b];
      if (ranks[a] > ranks[b]) swap(a, b);
      // b has higher rank
      parents[a] = b;
      sizes[b] = size;
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};

vector<vector<int>> nbrs;
int l, n;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i)
    up[v][i] = up[up[v][i-1]][i-1];

  for (int u : nbrs[v]) {
    if (u != p)
      dfs(u, v);
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}


int lca(int u, int v)
{
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

void preprocess(int root) {
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vector<int>(l + 1));
  dfs(root, root);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m;
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

  preprocess(0);
  for (pair<int, int> p: queries) {
    int u = p.first;
    int v = p.second;
    vector<int> path;
    vector<int> pathv;
    int k = lca(u, v);
    while (u != k) {
      path.push_back(u);
      u = up[u][0];
    }
    path.push_back(k);
    while (v != k) {
      pathv.push_back(v);
      v = up[v][0];
    }
    reverse(pathv.begin(), pathv.end());
    path.insert(path.end(), pathv.begin(), pathv.end());
    cout << path.size() << '\n';
    for (int i: path) {
      cout << i+1 << " ";
    }
    cout << '\n';
  }
}