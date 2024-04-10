#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 2e5 + 10;

int min_div[N];
void prec() {
  for (int i = 2; i < N; ++i) {
    if (min_div[i] == 0) {
      min_div[i] = i;
      for (ll j = (ll)i * i; j < N; j += i) {
        if (!min_div[j]) {
          min_div[j] = i;
        }
      }
    }
  }
}

ll pw(ll x, ll a) {
  if (!a) return 1;
  if (a % 2) return pw(x, a - 1) * x % MOD;
  ll tmp = pw(x, a / 2);
  return tmp * tmp % MOD;
}

class Solver {
public:

  void solve() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
      int v, u, x, y;
      cin >> v >> u >> x >> y;
      ll gg = __gcd(x, y);
      x /= gg;
      y /= gg;
      v--, u--;
      swap(x, y);
      g[v].push_back({u, {x, y}});
      g[u].push_back({v, {y, x}});
    }

    bal.resize(n + 1);
    min_bal.resize(n + 1);
    dfs(0);

    ll zer = 1;
    for (int i = 1; i <= n; ++i) {
      if (min_bal[i]) {
        zer = zer * pw(i, -min_bal[i]) % MOD;
      }
      assert(bal[i] == 0);
    }
    // cout << zer << "\n";

    cout << calc_ans(0, zer) << "\n";
  }

private:
  vector<vector<pair<int, pair<int, int>>>> g;
  vector<int> bal, min_bal;

  ll calc_ans(int v, ll val, int par = -1) {
    ll val_0 = val;
    for (auto [u, ab] : g[v]) {
      if (u == par) continue;
      ll val_u = val_0 * ab.first % MOD * pw(ab.second, MOD - 2) % MOD;
      val = (val + calc_ans(u, val_u, v)) % MOD;
    }
    return val;
  }

  vector<pair<int, int>> get_primes(int x) {
    if (x <= 1) return {};
    vector<pair<int, int>> p;
    while (x > 1) {
      auto d = min_div[x];
      int cnt = 0;
      while (x % d == 0) {
        cnt++;
        x /= d;
      }
      p.push_back({d, cnt});
    }
    return p;
  }

  void dfs(int v, int par = -1) {
    for (auto [u, ab] : g[v]) {
      if (u == par) continue;
      int a = ab.first;
      int b = ab.second;
      auto p_a = get_primes(a);
      auto p_b = get_primes(b);
      for (auto [p, cnt] : p_a) {
        bal[p] += cnt;
      }
      for (auto [p, cnt] : p_b) {
        bal[p] -= cnt;
        min_bal[p] = min(min_bal[p], bal[p]);
      }
      dfs(u, v);
      for (auto [p, cnt] : p_a) {
        bal[p] -= cnt;
      }
      for (auto [p, cnt] : p_b) {
        bal[p] += cnt;
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  prec();
  int t = 1;
  cin >> t;
  while (t--) {
    Solver{}.solve();
  }
}