#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int pr[N], rnk[N];

struct edge {
    int v, u, w;
};

void build(int v) {
    rnk[v] = 0;
    pr[v] = v;
}

int findSet(int v) {
    if (v == pr[v]) return v;
    int t = findSet(pr[v]);
    pr[v] = t;
    return t;
}

void unionSets(int a, int b) {
    int a1 = findSet(a);
    int b1 = findSet(b);
    if (a1 == b1) return;
    if (rnk[a1] < rnk[b1]) swap(a1, b1);
    if (rnk[a1] > rnk[b1])
        pr[b1] = a1;
    else {
        pr[b1] = a1;
        rnk[a1]++;
    }
}

class Solver {
public:

  void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
      int v, u;
      cin >> v >> u;
      g[--v].push_back({--u, i});
      g[u].push_back({v, i});
      edges[i] = {v, u, i};
    }

    is_good.resize(m, false);
    build_ost(n);

    //for (auto e : is_good) cout << e;cout << endl;

    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs_lca(0);

    sums.resize(n);
    for (int i = 0; i < m; ++i) {
      if (!is_good[i]) {
        int v = edges[i].v;
        int u = edges[i].u;
        int lca = get_lca(v, u);
        //cout << edges[i].v << " " << edges[i].u << ", lca: " << lca << endl;
        if (lca == v || lca == u) {
          if (lca == u) swap(v, u);
          // lca = v
          int pred_lca = get_pred_lca(v, u);
          sums[pred_lca]++;
          sums[u]--;
        } else {
          sums[edges[i].v]--;
          sums[edges[i].u]--;
          sums[0]++;
        }
      }
    }
    
    dfs_sums(0, sums[0]);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      if (sums[i] == 0) {
        ans[i] = 1;
      } else {
        ans[i] = 0;
      }
    }
    for (auto e : ans) {
      cout << e;
    }
    cout << endl;
  }

private:
  int l;
  vector<vector<pair<int, int>>> g;
  vector<int> is_good;
  vector<edge> edges;
  vector<int> sums;


  vector<int> tin, tout;
  int timer;
  vector<vector<int>> up;

  void dfs_sums(int v, int sm, int par = -1) {
    for (auto u : g[v]) {
      if (is_good[u.second] && u.first != par) {
        int new_sm = sm + sums[u.first];
        sums[u.first] = new_sm;
        dfs_sums(u.first, new_sm, v);
      }
    }
  }

  void build_ost(int n) {
    for (int i = 0; i < n; ++i) {
      build(i);
    }
    for (auto t: edges) {
        if (findSet(t.v) != findSet(t.u)) {
            unionSets(t.v, t.u);
            is_good[t.w] = true;
        }
    }
  }


  void dfs_lca (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
      up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
      int to = g[v][i].first;
      if (to != p && is_good[g[v][i].second])
        dfs_lca (to, v);
    }
    tout[v] = ++timer;
  }

  bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
  }

  int get_pred_lca (int a, int b) {
    if (upper (b, a)) {
      swap(a, b);
    }

    for (int i=l; i>=0; --i) {
      if (!upper(up[b][i], a) && up[b][i] != a) {
        b = up[b][i];
      }
    }
    return b;
  }

  int get_lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
      if (! upper (up[a][i], b))
        a = up[a][i];
    return up[a][0];
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}