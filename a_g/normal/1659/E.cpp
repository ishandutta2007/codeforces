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
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> get<0>(edges[i]) >> get<1>(edges[i]) >> get<2>(edges[i]);
  }
  vector<dsu> DSU(30, dsu(n+1));
  for (int i = 0; i < 30; i++) {
    for (tuple<int, int, int>& edge: edges) {
      if (get<2>(edge)&(1<<i)) {
        DSU[i].join(get<0>(edge), get<1>(edge));
      }
    }
  }

  vector<dsu> DSU2(29, dsu(n+1));
  for (int i = 0; i < 29; i++) {
    for (tuple<int, int, int>& edge: edges) {
      int mask = (1<<(i+1))|1;
      if ((get<2>(edge)&mask) == mask) {
        DSU2[i].join(get<0>(edge), get<1>(edge));
      }
    }
  }

  vector<vector<bool>> kill(29, vector<bool>(n+1, 0));
  for (tuple<int, int, int>& edge: edges) {
    if (get<2>(edge) % 2 == 0) {
      for (int v: {get<0>(edge), get<1>(edge)}) {
        for (int i = 0; i < 29; i++) {
          kill[i][DSU2[i].root(v)] = 1;
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    bool zero = 0;
    for (int i = 0; i < 30; i++) {
      if (DSU[i].root(u) == DSU[i].root(v)) {
        zero = 1;
        break;
      }
    }
    if (zero) {
      cout << "0\n";
      continue;
    }
    
    bool one = 0;
    for (int i = 0; i < 29; i++) {
      if (kill[i][DSU2[i].root(u)]) {
        one = 1;
        break;
      }
    }

    if (one) {
      cout << "1\n";
      continue;
    }
    cout << "2\n";
  }
}