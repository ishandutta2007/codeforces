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
  int n, m;
  cin >> m >> n;
  vector<int> a(m);
  vector<int> b(n);
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int x;
      cin >> x;
      x--;
      edges.emplace_back(a[i]+b[x], i, x+m);
    }
  }
  sort(edges.begin(), edges.end(), greater<tuple<int, int, int>>());
  dsu D(n+m);
  long long ans = 0;
  for (tuple<int, int, int>& t: edges) {
    if (!D.join(get<1>(t), get<2>(t))) {
      ans += get<0>(t);
    }
  }
  cout << ans << '\n';
}