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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (auto& r : a) {
      for (auto& e : r) {
        cin >> e;
      }
    }

    map<int, vector<ll>> v1, v2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        v1[a[i][j]].push_back(i);
        v2[a[i][j]].push_back(j);
      }
    }

    ll ans = 0;
    for (auto& v : {v1, v2}) {
      for (auto [k, vec] : v) {
        ans += calc(vec);
      }
    }
    cout << ans << endl;

  }

private:
  ll calc(vector<ll>& a) {
    sort(a.begin(), a.end());
    ll ans = 0;
    ll n = a.size();
    for (ll i = 0; i < n; ++i) {
      ans += i * a[i];
      ans -= (ll)(n - 1 - i) * a[i];
    }
    return ans;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}