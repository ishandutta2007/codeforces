#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edges;
int n;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      ranks.resize(n, 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      int size = sizes[a] + sizes[b];
      if (ranks[a] > ranks[b]) swap(a, b);
      parents[a] = b;
      sizes[b] = size;
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};

bool valid(int z) {
  // is there spanning tree with OR a submask of z?
  dsu d(n);
  int joins = 0;
  for (tuple<int, int, int> e: edges) {
    int u, v, w;
    tie(u, v, w) = e;
    if ((w|z)==z) {
      joins += d.join(u-1, v-1);
    }
  }
  if (joins == n-1) return 1;
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({u, v, w});
    }

    int curr = 0;
    for (int i = 30; i >= 0; i--) {
      if (!valid(curr|((1<<i)-1))) {
        curr |= 1<<i;
      }
    }
    cout << curr << '\n';
    edges.clear();
  }
}