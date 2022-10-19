#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> sizes[2];
    vector<bool> opposite_of_parent;
    vector<bool> is_fixed;
    vector<bool> root_is_on;
    int ans = 0;
    int n;
    dsu (int n): n(n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      ranks.resize(n, 0);
      sizes[0].resize(n, 0);
      sizes[1].resize(n, 1);
      opposite_of_parent.resize(n, 0);
      is_fixed.resize(n, 0);
      root_is_on.resize(n, 0);
    }
    int root(int u) {
      if (parents[u] == u) return u;
      bool x = opposite_of_parent[u];
      int rt = root(parents[u]);
      bool y = opposite_of_parent[parents[u]];
      opposite_of_parent[u] = (x != y);
      parents[u] = rt;
      return rt;
    }
    int contribution(int u) {
      assert(parents[u] == u);
      if (is_fixed[u]) {
        return (sizes[root_is_on[u]][u]);
      }
      return min(sizes[0][u], sizes[1][u]);
    }
    bool join(int u, int v, bool y) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      assert(a == parents[u] && b == parents[v]);
      bool newval = opposite_of_parent[u] != (opposite_of_parent[v] != y);
      int oldcontrib = contribution(a) + contribution(b);
      if (ranks[a] > ranks[b]) swap(a, b);
      parents[a] = b;
      opposite_of_parent[a] = newval;
      if (ranks[a] == ranks[b]) ranks[b]++;
      if (is_fixed[a]) {
        is_fixed[b] = 1;
        root_is_on[b] = root_is_on[a] != opposite_of_parent[a];
      }
      if (opposite_of_parent[a]) {
        sizes[0][b] += sizes[1][a];
        sizes[1][b] += sizes[0][a];
      }
      else {
        sizes[0][b] += sizes[0][a];
        sizes[1][b] += sizes[1][a];
      }
      int newcontrib = contribution(b);
      ans += newcontrib-oldcontrib;
      return 1;
    }
    void fix(int u, bool b) {
      int v = root(u);
      int oldcontrib = contribution(v);
      is_fixed[v] = 1;
      assert(parents[u] == v);
      if (opposite_of_parent[u]) root_is_on[v] = 1-b;
      else root_is_on[v] = b;
      int newcontrib = contribution(v);
      ans += newcontrib-oldcontrib;
    }

    void debug() {
      for (int i = 0; i < n; i++) {
        cout << i << " " << parents[i] << " " << sizes[0][i] << " " << sizes[1][i] << " " << opposite_of_parent[i] << " " << is_fixed[i] << " " << root_is_on[i] << '\n';
      }
      cout << ans << '\n';
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<vector<int>> lamps(n);
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      lamps[x-1].push_back(i);
    }
  }

  dsu d(k);
  for (int i = 0; i < n; i++) {
    //cout << "------------------\n";
    //cout << i << endl;
    //for (int k: lamps[i]) cout << k << ' ';
    //cout << '\n';
    if (lamps[i].size() == 1) {
      d.fix(lamps[i][0], (s[i] == '1' ? 0 : 1));
    }
    else if (lamps[i].size() == 2) {
      d.join(lamps[i][0], lamps[i][1], (s[i] == '1' ? 0 : 1));
    }
    //d.debug();
    cout << d.ans << '\n';
  }
}