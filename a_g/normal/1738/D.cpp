#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int& x: b) cin >> x;
    vector<vector<int>> G(n+2);
    int k = 0, kr = n+2;
    for (int i = 0; i < n; i++) {
      if (i+1 < b[i]) {
        kr = min(kr, b[i]-1);
        k = max(k, i+1);
      }
      else {
        kr = min(kr, i);
        k = max(k, b[i]);
      }
      if (b[i] == 0 || b[i] == n+1) {
        G[0].emplace_back(i+1);
      }
      else {
        G[b[i]].emplace_back(i+1);
      }
    }
    k = min(k, kr);
    cout << k << '\n';
    vector<int> topo;
    for (int i = 0; i <= n; i++) {
      sort(G[i].begin(), G[i].end(), [&] (int x, int y) {
          return G[x].size() < G[y].size();
          });
    }
    topo.emplace_back(0);
    while (G[topo.back()].size()) {
      for (int x: G[topo.back()]) topo.emplace_back(x);
    }
    assert((int)topo.size() == n+1);
    for (int i = 1; i <= n; i++) {
      cout << topo[i] << " \n"[i==n];
    }
  }
}