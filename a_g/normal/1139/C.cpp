#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

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

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  dsu D(n);
  for (int i = 0; i < n-1; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--;
    if (!x) D.join(u, v);
  }

  int ans = expmod(n, k, MOD);
  for (int i = 0; i < n; i++) {
    if (D.parents[i] == i) {
      int m = D.sizes[i];
      ans -= expmod(m, k, MOD);
      if (ans < 0) ans += MOD;
    }
  }
  cout << ans << '\n';
}