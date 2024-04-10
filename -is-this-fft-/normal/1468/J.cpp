#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class DSU {
  vector<int> root;

public:
  DSU (int _n) : root(_n) {
    for (int i = 0; i < _n; i++) {
      root[i] = i;
    }
  }

  int find (int u) {
    if (root[u] != u) {
      root[u] = find(root[u]);
    }
    return root[u];
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    root[u] = v;
  }
};

struct Edge {
  int u, v;
  ll w;

  Edge (int _u = 0, int _v = 0, ll _w = 0) : u(_u), v(_v), w(_w) {}
};

bool operator< (Edge e, Edge f) {
  return e.w < f.w;
}

void solve () {
  int n, m, K;
  cin >> n >> m >> K;

  vector<Edge> small, big;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    if (w <= K) {
      small.push_back(Edge(u, v, w));
    } else {
      big.push_back(Edge(u, v, w - K));
    }
  }

  sort(small.begin(), small.end());
  sort(big.begin(), big.end());

  int added = 0;
  DSU dsu (n + 1);
  for (Edge e : small) {
    if (dsu.find(e.u) != dsu.find(e.v)) {
      added++;
      dsu.merge(e.u, e.v);
    }
  }

  ll cost = 0;
  for (Edge e : big) {
    if (dsu.find(e.u) != dsu.find(e.v)) {
      added++;
      cost += e.w;
      dsu.merge(e.u, e.v);
    }
  }

  if (cost == 0) {
    ll add = 1e18 + 5;
    if (!small.empty()) {
      add = min(add, K - small.back().w);
    }

    if (!big.empty()) {
      add = min(add, big.front().w);
    }

    cost += add;
  }

  cout << cost << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}