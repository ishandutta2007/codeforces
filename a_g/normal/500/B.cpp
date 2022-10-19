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
  int n;
  cin >> n;
  vector<int> p(n);
  for (int& x: p) cin >> x;

  dsu D(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        D.join(i, j);
      }
    }
  }

  vector<vector<int>> by_root(n), indices(n);
  for (int i = 0; i < n; i++) {
    by_root[D.root(i)].push_back(p[i]);
    indices[D.root(i)].push_back(i);
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (D.root(i) != i) continue;
    sort(by_root[i].begin(), by_root[i].end());
    for (int j = 0; j < (int)indices[i].size(); j++) {
      ans[indices[i][j]] = by_root[i][j];
    }
  }
  for (int x: ans) {
    cout << x << ' ';
  }
  cout << '\n';
}