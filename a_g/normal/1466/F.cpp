#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    vector<bool> active;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
      active.resize(n, 0);
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
      if (active[a] && active[b]) return 0;
      if (active[a]) active[b] = 1;
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu D(m+1);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    if (k == 1) {
      int v;
      cin >> v;
      if (!D.active[D.root(v)]) {
        ans.push_back(i);
        D.active[D.root(v)] = 1;
      }
    }
    else {
      assert(k == 2);
      int u, v;
      cin >> u >> v;
      if (D.join(u, v)) {
        ans.push_back(i);
      }
    }
  }

  int c = 1;
  for (int k: ans) {
    c = 2LL * c % MOD;
  }
  cout << c << " " << ans.size() << '\n';
  for (int k: ans) {
    cout << k << ' ';
  }
  cout << '\n';
}