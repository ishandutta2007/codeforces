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
    a.resize(n);
    for (auto& e : a) {
      cin >> e;
    }
    ll ans = 1e18;
    for (int i = 0; i < n; ++i) {
      ll cur = 0;
      ll last = 0;
      for (int j = i + 1; j < n; ++j) {
        ll cnt = (last / a[j] + 1);
        cur += cnt;
        last = cnt * a[j];
      }
      last = 0;
      for (int j = i - 1; j >= 0; --j) {
        ll cnt = (last / a[j] + 1);
        cur += cnt;
        last = cnt * a[j];
      }
      ans = min(ans, cur);
    }
    cout << ans << endl;
  }

private:
  vector<ll> a;

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}