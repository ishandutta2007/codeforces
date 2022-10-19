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
  vector<vector<bool>> grid(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      grid[i][j] = s[j] == '#';
    }
  }

  bool emptyrow = 0;
  for (int i = 0; i < n; i++) {
    bool start = 0;
    bool end = 0;
    for (int j = 0; j < m; j++) {
      if (grid[i][j]) {
        if (end) {
          cout << "-1\n";
          return 0;
        }
        start = 1;
      }
      else {
        if (start) {
          end = 1;
        }
      }
    }
    if (!start) emptyrow = 1;
  }

  bool emptycol = 0;
  for (int j = 0; j < m; j++) {
    bool start = 0;
    bool end = 0;
    for (int i = 0; i < n; i++) {
      if (grid[i][j]) {
        if (end) {
          cout << "-1\n";
          return 0;
        }
        start = 1;
      }
      else {
        if (start) {
          end = 1;
        }
      }
    }
    if (!start) emptycol = 1;
  }

  if (emptyrow+emptycol == 1) {
    cout << "-1\n";
    return 0;
  }
  
  dsu D(n+m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j]) D.join(i, j+n);
    }
  }
  vector<bool> take(n+m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j]) take[D.root(i)] = 1;
    }
  }
  cout << accumulate(take.begin(), take.end(), 0) << '\n';
}