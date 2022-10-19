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
  int n, m, k;
  cin >> n >> m >> k;
  dsu D(n);
  vector<int> c(k);
  for (int& x: c) {
    cin >> x;
    x--;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    D.join(u, v);
  }
  for (int& x: c) x = D.root(x);
  int free_vertices = 0;
  for (int i = 0; i < n; i++) {
    if (D.root(i) == i) {
      free_vertices += D.sizes[i];
    }
  }

  for (int& x: c) {
    free_vertices -= D.sizes[x];
    x = D.sizes[x];
  }
  sort(c.begin(), c.end());
  c.back() += free_vertices;
  int ans = -m;
  for (int& x: c) {
    ans += x*(x-1)/2;
  }
  cout << ans << '\n';
}