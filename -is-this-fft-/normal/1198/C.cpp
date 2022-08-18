#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  set<int> seen_ends;
  vector<int> kept_edges;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    if (!seen_ends.count(u) && !seen_ends.count(v)) {
      kept_edges.push_back(i + 1);
      seen_ends.insert(u);
      seen_ends.insert(v);
    }
  }

  if ((int) kept_edges.size() >= n) {
    cout << "Matching" << '\n';
    for (int i = 0; i < n; i++) {
      cout << kept_edges[i] << " ";
    }
    cout << '\n';
    return;
  }

  vector<int> indset;
  for (int i = 1; i <= 3 * n; i++) {
    if (!seen_ends.count(i)) {
      indset.push_back(i);
    }
  }

  cout << "IndSet" << '\n';
  for (int i = 0; i < n; i++) {
    cout << indset[i] << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}