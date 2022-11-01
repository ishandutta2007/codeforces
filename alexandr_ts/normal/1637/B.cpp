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
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = i; j < n; ++j) {
        if (a[j] == 0) cnt++;
        ans += (j - i + 1 + cnt);
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