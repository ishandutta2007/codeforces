#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p;
      p--;
      g[p].push_back(i);
    }

    ans = 0;
    for (int i = 0; i < n; ++i) {
      if (g[i].empty()) ans++;
    }

    l.resize(n);
    r.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
    }
    dfs(0);
    cout << ans << "\n";
  }

private:
  int ans;
  vector<vector<int>> g;
  vector<ll> l, r;

  pair<ll, ll> dfs(int v) {
    if (g[v].empty()) {
      return {l[v], r[v]};
    }
    vector<pair<ll, ll>> a;
    for (auto u : g[v]) {
      a.push_back(dfs(u));
    }
    sort(a.begin(), a.end());

    ll l1 = 0;
    ll r1 = 0;
    for (auto el : a) {
      r1 += el.second;
    }
    if (l[v] > r1 || l1 > r[v]) {
      ans++;
      return {l[v], r[v]};
    }
    return {max(l[v], l1), min(r[v], r1)};
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solver{}.solve();
  }
}