#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
const int K = 20;
vector<int> G[N];
int depth[N], tin[N], tout[N];
int par[N][K];
int timer = 0;

void dfs(int v, int p) {
  par[v][0] = p;
  for (int i = 1; i < K; i++) {
    par[v][i] = par[par[v][i-1]][i-1];
  }
  tin[v] = timer++;
  for (int u: G[v]) {
    if (u == p) continue;
    depth[u] = depth[v]+1;
    dfs(u, v);
  }
  tout[v] = timer++;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  if (is_ancestor(v, u)) {
    return v;
  }
  for (int i = K-1; i >= 0; --i) {
    if (!is_ancestor(par[u][i], v))
      u = par[u][i];
  }
  return par[u][0];
}

int anc(int u, int l) {
  for (int i = K-1; i >= 0; i--) {
    if (l&(1<<i)) {
      u = par[u][i];
    }
  }
  return u;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);

  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int& x: a) cin >> x;
    if (k == 1) {
      cout << "YES\n";
      continue;
    }
    int top = a[0];
    for (int i = 1; i < k; i++) {
      top = lca(top, a[i]);
    }

    vector<int> c;
    for (int v: a) {
      if (v != top) {
        c.push_back(anc(v, depth[v]-depth[top]-1));
      }
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end())-c.begin());
    if (c.size() > 2) {
      cout << "NO\n";
      continue;
    }
    vector<vector<int>> sides(c.size());
    for (int v: a) {
      if (v != top) {
        for (int i = 0; i < (int)c.size(); i++) {
          if (anc(v, depth[v]-depth[top]-1) == c[i]) {
            sides[i].push_back(v);
          }
        }
      }
    }

    bool good = 1;
    for (int i = 0; i < (int)c.size(); i++) {
      sort(sides[i].begin(), sides[i].end(), [&] (int u, int v) {return depth[u] < depth[v];});
      for (int j = 0; j < (int)sides[i].size()-1; j++) {
        if (!is_ancestor(sides[i][j], sides[i][j+1])) {
          good = 0;
          break;
        }
      }
    }

    cout << (good ? "YES" : "NO") << '\n';
  }

}