#include <bits/stdc++.h>
using namespace std;

const int N = 6e5+2;
bool used_edge[N/2], vis[N];
vector<pair<int, int>> G[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    G[x].emplace_back(y, i);
    G[y].emplace_back(x, i);
  }

  vector<int> cyc;
  function<void(int)> dfs = [&] (int v) {
    vis[v] = 1;
    for (pair<int, int>& e: G[v]) {
      if (used_edge[e.second]) continue;
      used_edge[e.second] = 1;
      if (vis[e.first]) {
        cyc.push_back(e.first);
        cyc.push_back(v);
      }
      else {
        cyc.push_back(e.first);
        dfs(e.first);
        cyc.push_back(v);
      }
    }
  };
  vector<vector<int>> grid(2);
  string dom[2];
  for (int i = 1; i <= 2*n; i++) {
    if (vis[i]) continue;
    dfs(i);
    int k = (int)cyc.size()/2;
    if (k == 1) {
      cout << "-1\n";
      return 0;
    }
    if (k == 0) continue;
    for (int i = 0; i < k; i++) {
      grid[0].push_back(cyc[i]);
    }
    for (int i = 2*k-1; i >= k; i--) {
      grid[1].push_back(cyc[i]);
    }

    if (k%2 == 0) {
      for (int i = 0; i < k/2; i++) dom[0] += "LR";
      dom[1] += 'U';
      for (int i = 0; i < k/2-1; i++) dom[1] += "LR";
      dom[1] += 'U';
    }
    else {
      dom[0] += 'U';
      for (int i = 0; i < k/2; i++) {
        dom[0] += "LR";
        dom[1] += "LR";
      }
      dom[1] += 'U';
    }
    cyc.clear();
  }

  cout << 2 << " " << n << '\n';
  for (vector<int>& row: grid) {
    for (int j: row) {
      cout << j << ' ';
    }
    cout << '\n';
  }
  for (string& s: dom) {
    cout << s << '\n';
    for (char& c: s) {
      if (c == 'U') c = 'D';
    }
    cout << s << '\n';
  }
}