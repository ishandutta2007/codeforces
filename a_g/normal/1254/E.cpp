#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int K = 20;
const int MOD = 1e9+7;
int par[N][K], dep[N], first[N], last[N];
vector<int> G[N];
vector<pair<int, int>> C[N];
int vis[N], before[N], after[N];

void fail() {
  cout << "0\n";
  exit(0);
}

void dfs(int v, int p) {
  dep[v] = dep[p]+1;
  par[v][0] = p;
  for (int i = 1; i < K; i++) {
    par[v][i] = par[par[v][i-1]][i-1];
  }
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = K-1; i >= 0; i--) {
    if (dep[u] <= dep[par[v][i]]) v = par[v][i];
  }
  if (u == v) return u;
  for (int i = K-1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[v][0];
}

vector<int> query_path(int u, int v) {
  int w = lca(u, v);
  vector<int> path;
  while (u != w) {
    path.push_back(u);
    u = par[u][0];
  }
  path.push_back(w);

  vector<int> other;
  while (v != w) {
    other.push_back(v);
    v = par[v][0];
  }
  reverse(other.begin(), other.end());
  for (int x: other) {
    path.push_back(x);
  }
  return path;
};

void set_val(int* p, int u) {
  if (*p != 0 && *p != u) fail();
  *p = u;
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
  dfs(1, 0);

  int total_dist = 0;
  for (int v = 1; v <= n; v++) {
    int u;
    cin >> u;
    if (u) {
      if (u == v) fail();
      vector<int> path = query_path(u, v);
      int k = path.size();
      total_dist += k-1;
      if (total_dist > 2*(n-1)) fail();
      set_val(first+path[0], path[1]);
      set_val(last+path[k-1], path[k-2]);
      for (int i = 1; i < k-1; i++) {
        C[path[i]].emplace_back(path[i-1], path[i+1]);
      }
    }
  }

  int ans = 1;
  for (int v = 1; v <= n; v++) {
    for (int u: G[v]) {
      before[u] = 0;
      after[u] = 0;
      vis[u] = 0;
    }
    for (pair<int, int>& p: C[v]) {
      if (p.first == last[v]) fail();
      if (p.second == first[v]) fail();
      set_val(after+p.first, p.second);
      set_val(before+p.second, p.first);
    }
    int time = 1;
    int edges = 0;
    for (int u: G[v]) {
      // check for cycles
      if (after[u]) edges++;
      if (vis[u]) continue;
      int x = u;
      while (!vis[x]) {
        vis[x] = time;
        if (!after[x]) break;
        if (vis[after[x]] == time) fail();
        x = after[x];
      }
      time++;
    }
    if (first[v] && last[v]) {
      int from_first = first[v];
      while (after[from_first]) from_first = after[from_first];
      if (from_first == last[v] && edges != (int)G[v].size()-1) fail();
    }
    int pieces = (int)G[v].size()-edges-(first[v] != 0)-(last[v] != 0);
    for (int i = 1; i <= pieces; i++) {
      ans = 1LL*i*ans % MOD;
    }
  }
  cout << ans << '\n';
}