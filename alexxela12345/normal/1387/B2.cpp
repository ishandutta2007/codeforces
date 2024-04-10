#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<vector<int>> g;

vector<int> sz;
vector<int> used;

int centr = -1;
int ans2 = 0;

void dfs(int v) {
  used[v] = 1;
  sz[v] = 1;
  int mx = 0;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
      sz[v] += sz[u];
      mx = max(mx, sz[u]);
    }
  }
  for (int u : g[v]) {
    if (used[u] == 2)
      ans2 += min(sz[u], n - sz[u]) * 2;
  }
  if (mx * 2 <= n && (n - sz[v]) * 2 <= n) {
    centr = v;
  }
  used[v] = 2;
}

vector<int> ord;

void dfs2(int v) {
  ord.push_back(v);
  used[v] = 1;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs2(u);
    }
  }
}


set<int> leafs;

signed main() {
  cin >> n;
  g.resize(n);
  sz.resize(n);
  used.resize(n);;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  used.assign(n, 0);
  dfs2(centr);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[ord[i]] = ord[(i + n / 2) % n];
  }
  cout << ans2 << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " ";
  }
}