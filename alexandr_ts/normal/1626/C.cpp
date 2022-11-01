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
    h.resize(n);
    k.resize(n);
    for (auto& e : k) cin >> e;
    for (auto& e : h) cin >> e;

    for (int i = n - 2; i >= 0; --i) {
      h[i] = max(h[i], h[i + 1] - k[i + 1] + k[i]);
    }

    for (int i = 1; i < n; ++i) {
      if (h[i] - h[i - 1] == k[i]- k[i - 1]) continue;
      if (h[i] > k[i] - k[i - 1]) {
        h[i] = h[i - 1] + k[i] - k[i - 1];
      }
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (i && h[i] - h[i - 1] == k[i] - k[i - 1]) {
        ans += sum(h[i - 1] + 1, h[i]);
      } else {
        ans += sum(1, h[i]);
      }
    }
    cout << ans << "\n";
  }

private:
  vector<ll> h, k;
  ll sum(ll l, ll r) {
    return (l + r) * (r - l + 1) / 2;
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