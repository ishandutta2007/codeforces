#include <bits/stdc++.h>
using namespace std;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    dsu D(n);
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (a[j][i] < a[i][j]) {
          // b[i]+b[j] = 1
          if (D.join(i, j)) {
            G[i].emplace_back(j, 1);
            G[j].emplace_back(i, 1);
          }
        }
        else if (a[i][j] < a[j][i]) {
          // b[i]+b[j] = 0
          if (D.join(i, j)) {
            G[i].emplace_back(j, 0);
            G[j].emplace_back(i, 0);
          }
        }
      }
    }

    vector<bool> vis(n, 0);
    vector<int> b(n);
    function<void(int)> dfs = [&] (int v) {
      if (vis[v]) return;
      vis[v] = 1;
      for (pair<int, int>& e: G[v]) {
        int u = e.first;
        int k = e.second;
        b[u] = b[v]^k;
        dfs(u);
      }
    };
    for (int v = 0; v < n; v++) {
      dfs(v);
    }

    for (int i = 0; i < n; i++) {
      if (b[i]) {
        for (int j = 0; j < n; j++) {
          swap(a[i][j], a[j][i]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j] << " \n"[j+1==n];
      }
    }
  }
}