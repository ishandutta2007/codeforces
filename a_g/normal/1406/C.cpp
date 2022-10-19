#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int z[N], sts[N];
vector<int> G[N];
vector<int> centroids;

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

    function<void(int, int)> dfs = [&] (int v, int p) {
      sts[v] = 1;
      for (int u: G[v]) {
        if (u != p) {
          dfs(u, v);
          z[v] = max(z[v], sts[u]);
          sts[v] += sts[u];
        }
      }
      z[v] = max(z[v], n-sts[v]);
    };
    dfs(1, 1);

    int m = *min_element(z+1, z+n+1);
    vector<int> centroids;
    for (int i = 1; i <= n; i++) {
      if (z[i] == m) {
        centroids.push_back(i);
      }
    }

    if (centroids.size() == 1) {
      for (int j = 0; j < 2; j++) {
        cout << 1 << " " <<  G[1][0] << '\n';
      }
    }
    else {
      int k;
      for (int u: G[centroids[0]]) {
        if (u != centroids[1]) {
          k = u;
          break;
        }
      }
      cout << centroids[0] << " " << k << '\n';
      cout << centroids[1] << " " << k << '\n';
    }

    for (int i = 1; i <= n; i++) {
      G[i].clear();
      z[i] = 0;
    }
  }
}