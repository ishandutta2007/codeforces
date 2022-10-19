#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// source: Talentkkggg (https://codeforces.com/problemset/submission/1555/133425129)

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
      return parents[u] == u ? u : parents[u] = root(parents[u]);
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

class fenwick {
  public:
    vector<int> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, int val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    int query(int index) {
      int sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

int l, n, timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> parity;
vector<vector<pii>> adj(n);

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i)
    up[v][i] = up[up[v][i-1]][i-1];

  for (pii u : adj[v]) {
    if (u.first != p) {
      parity[u.first] = parity[v]^u.second;
      dfs(u.first, v);
    }
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
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


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> q;
  dsu d(n);
  vector<tuple<int, int, int>> queries(q);
  vector<bool> ans(q);
  adj.resize(n);
  for (int i = 0; i < q; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--;
    queries[i] = {u, v, x};
    if (d.join(u, v)) {
      ans[i] = 1;
      d.join(u, v);
      adj[u].push_back({v, x});
      adj[v].push_back({u, x});
    }
  };

  tin.resize(n);
  tout.resize(n);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vector<int>(l + 1));
  parity.resize(n);

  for (int i = 0; i < n; i++) {
    if (!tin[i]) dfs(i, i);
  }
  fenwick f(2*n);
  for (int i = 0; i < q; i++) {
    if (!ans[i]) {
      int u, v, x;
      tie(u, v, x) = queries[i];
      int w = lca(u, v);
      if (parity[u]^parity[v]^x &&
          f.query(tin[u]) + f.query(tin[v]) - 2*f.query(tin[w]) == 0) {
        ans[i] = 1;
        while (u != w) {
          f.add(tin[u], 1);
          f.add(tout[u], -1);
          u = up[u][0];
        }
        while (v != w) {
          f.add(tin[v], 1);
          f.add(tout[v], -1);
          v = up[v][0];
        }
      }
    }
  }
  for (bool b: ans) cout << (b ? "YES\n" : "NO\n");
}