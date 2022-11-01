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

  ll solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    //int mn = *min_element(a.begin() + 1, prev(a.end()));
    int mx = *max_element(a.begin() + 1, prev(a.end()));

    if (mx == 0) return 0;
    if (mx == 1) return -1;
    if (n == 3 && a[1] % 2) return -1;
    ll ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
      ans += ((ll)a[i] + 1) / 2;
    }
    return ans;
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << Solver{}.solve() << "\n";
  }
}