#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> edges;

void add_edge (int u, int v) {
  if (u > v) {
    swap(u, v);
  }

  edges.insert(make_pair(u, v));
}

bool has_edge (int u, int v) {
  if (u > v) {
    swap(u, v);
  }

  return edges.count(make_pair(u, v));
}

void solve () {
  edges.clear();
  
  int n, p;
  cin >> n >> p;

  for (int i = 0; i < n; i++) {
    add_edge(i, (i + 1) % n);
    add_edge(i, (i + 2) % n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (p > 0 && !has_edge(i, j)) {
        p--;
        add_edge(i, j);
      }
    }
  }

  for (auto e : edges) {
    cout << e.first + 1 << " " << e.second + 1 << '\n';
  }  
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}