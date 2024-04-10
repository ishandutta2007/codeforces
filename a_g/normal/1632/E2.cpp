#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
vector<int> nbrs[N];
vector<int> z[N]; // m[u]-d[u] over children of v
vector<int> children[N];
int diam[N]; // diameter of subtree
int n;
int ans[N];
int d[N];
int d2[N];
int parent[N];
int m[N]; // max depth in this subtree
int f[N];
int u[N]; // given dist, largest x that works
int seed;

void dfs(int v, int p) {
  parent[v] = p;
  if (v != p) children[p].push_back(v);
  m[v] = d[v];
  for (int u: nbrs[v]) {
    if (u != p) {
      d[u] = d[v] + 1;
      dfs(u, v);
      m[v] = max(m[v], m[u]);
      z[v].push_back(m[u]-d[u]);
      diam[v] = max(diam[v], diam[u]);
    }
  }
  diam[v] = max(diam[v], m[v] - d[v]);
  if (z[v].size() >= 2) {
    nth_element(z[v].begin(), z[v].begin()+1, z[v].end(), greater<int>());
    diam[v] = max(diam[v], z[v][0] + z[v][1]+2);
  }
}

void dfs2(int v, int k) {
  seed = v;
  k = max(k, d[v]);
  f[v] = k;
  if (!children[v].size()) return;
  if (children[v].size() == 1) {
    dfs2(children[v][0], k);
    return;
  }
  if (z[v][0] == z[v][1]) return;
  for (int u: children[v]) {
    if (m[u]-d[u] == z[v][0]) {
      dfs2(u, max(z[v][1] + d[v] + 2, k));
      return;
    }
  }
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }

    dfs(1, 1);
    seed = 1;
    dfs2(1, 0);

    int cur = n;
    while (cur >= 1) {
      while (seed != 1 && f[seed] > cur+1) seed = parent[seed];
      if (m[seed] <= cur) {
        u[cur] = n+1;
      }
      else {
        u[cur] = cur-(diam[seed]+1)/2;
      }
      cur--;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = max(1, u[i-1]+1); j <= u[i]; j++) {
        ans[j] = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
      nbrs[i].clear();
      z[i].clear();
      children[i].clear();
      f[i] = 0;
      diam[i] = 0;
    }
  }
}