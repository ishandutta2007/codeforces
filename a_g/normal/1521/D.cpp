#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> G[N];
int par[N];
bool del[N], vis[N];

void dfs(int v, int p) {
  par[v] = p;
  int e = 0;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    if (!del[u]) e++;
  }
  for (int u: G[v]) {
    if (u == p) continue;
    if (e > 2 && !del[u]) {
      del[u] = 1;
      e--;
    }
  }
  if (v != p && e == 2) del[v] = 1;
}

int dfs2(int v, int p) {
  vis[v] = 1;
  for (int u: G[v]) {
    if (u == p) continue;
    return dfs2(u, v);
  }
  return v;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, 1);
    vector<int> deleted;
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      if (del[i]) deleted.push_back(i);
    }
    cout << deleted.size() << '\n';

    for (int i = 2; i <= n; i++) {
      if (!del[i]) {
        G[i].push_back(par[i]);
        G[par[i]].push_back(i);
      }
    }
    vector<pair<int, int>> endpts;
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && G[i].size() <= 1) endpts.emplace_back(i, dfs2(i, i));
    }
    assert(endpts.size() == deleted.size()+1);
    for (int i = 0; i < (int)deleted.size(); i++) {
      cout << deleted[i] << " " << par[deleted[i]] << " " << endpts[i].second << " " << endpts[i+1].first << '\n';
    }

    for (int i = 1; i <= n; i++) {
      G[i].clear();
      del[i] = 0;
      vis[i] = 0;
    }
  }
}