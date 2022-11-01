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
    ll x;
    cin >> n;
    cin >> x;
    multiset<ll> s;
    for (int i = 0; i < n; ++i) {
      ll k;
      cin >> k;
      s.insert(k);
    }
    int ans = 0;
    while (!s.empty()) {
      auto it = s.begin();
      ll k = *it;
      s.erase(s.begin());
      auto it2 = s.find(x * k);
      if (it2 != s.end()) {
        s.erase(it2);
      } else {
        ans++;
      }
    }
    cout << ans << "\n";

  }

private:

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