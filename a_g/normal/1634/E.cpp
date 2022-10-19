#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
string ans[N];
map<int, set<pair<int, int>>> edges_r;
set<pair<int, int>> edges_l[N];

void dfs(int v) {
  if (!edges_l[v].size()) return;
  pair<int, int> e1 = *edges_l[v].begin();
  int a = e1.first;
  ans[v][e1.second] = 'L';
  edges_r[a].erase(make_pair(v, e1.second));
  edges_l[v].erase(e1);
  
  pair<int, int> e2 = *edges_r[a].begin();
  int i = e2.first;
  ans[i][e2.second] = 'R';
  edges_l[i].erase(make_pair(a, e2.second));
  edges_r[a].erase(e2);
  dfs(i);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;
    ans[i].resize(n);
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      edges_r[a].insert(make_pair(i, j));
      edges_l[i].insert(make_pair(a, j));
    }
  }

  for (auto& p: edges_r) {
    if (p.second.size() & 1) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";

  for (int i = 0; i < m; i++) {
    while (!edges_l[i].empty()) {
      dfs(i);
    }
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}