#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int p[N], a[N];
int indeg[N];
bool vis[N];
vector<pair<int, int>> G[N];
vector<int> G2[N];


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    int v = i;
    int num = 0;
    while (!vis[v]) {
      a[v] = num++;
      vis[v] = 1;
      v = p[v];
    }
  }

  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
  }

  for (int i = 1; i <= n; i++) {
    sort(G[i].begin(), G[i].end(), [&] (const pair<int, int>& e1, const pair<int, int>& e2) {
      return (a[i] > a[e1.first])^(a[e1.first] > a[e2.first])^(a[e2.first] > a[i]);
        });
    int z = G[i].size();
    for (int j = 0; j < z-1; j++) {
      G2[G[i][j].second].push_back(G[i][j+1].second);
      indeg[G[i][j+1].second]++;
    }
  }


  vector<int> que;
  for (int i = 1; i <= m; i++) {
    if (indeg[i] == 0) {
      que.push_back(i);
    }
  }
  
  for (int i = 0; i < (int)que.size(); i++) {
    for (int v: G2[que[i]]) {
      indeg[v]--;
      if (indeg[v] == 0) {
        que.push_back(v);
      }
    }
  }

  for (int i: que) {
    cout << i << ' ';
  }
  cout << '\n';
}