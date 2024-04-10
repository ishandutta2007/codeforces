#include <bits/stdc++.h>
using namespace std;

const int N = (1<<17)+3;
vector<int> G[N];
int P, cur, par[N], upval[N], val[N];

void dfs(int v, int p, bool b) {
  par[v] = p;
  if (v == p) {
    val[v] = 1<<P;
  }
  else {
    if (b) {
      val[v] = cur;
      upval[v] = cur+(1<<P);
    }
    else {
      val[v] = cur+(1<<P);
      upval[v] = cur;
    }
    cur++;
  }
  for (int u: G[v]) {
    if (u != p) {
      dfs(u, v, 1-b);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> P;
    int n = 1<<P;
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
      edges.emplace_back(u, v);
    }
    cur = 1;
    dfs(1, 1, 0);

    fill(G+1, G+n+1, vector<int>());
    cout << "1\n";
    for (int i = 1; i <= n; i++) {
      cout << val[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n-1; i++) {
      int u = edges[i].first;
      int v = edges[i].second;
      if (par[u] == v) {
        cout << upval[u];
      }
      else {
        cout << upval[v];
      }
      cout << " \n"[i==n-2];
    }
  }
}