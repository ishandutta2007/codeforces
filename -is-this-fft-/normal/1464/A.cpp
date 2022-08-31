#include <iostream>
#include <vector>

using namespace std;

class DSU {
  vector<int> root;
  
public:
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

  DSU (int _n) : root(_n) {
    for (int i = 0; i < _n; i++) {
      root[i] = i;
    }
  }
};

const int MAX_N = 1e5 + 5;

int x [MAX_N], y [MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
  }

  DSU dsu (n + m + 1);
  
  int dc = 0, cc = 0;
  for (int i = 0; i < m; i++) {
    if (x[i] == y[i]) {
      dc++;
    } else {
      dsu.merge(i, m + x[i]);
      if (dsu.find(i) == dsu.find(m + y[i])) {
        cc++;
      }
      dsu.merge(i, m + y[i]);
    }
  }

  cout << m - dc + cc << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}