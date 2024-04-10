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
    ll n, q;
    cin >> n >> q;
    a.resize(n);
    for (auto& e : a) cin >> e;

    int l = -1, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (ok(m, n, q)) {
        r = m;
      } else {
        l = m;
      }
    }
    assert(r < n);

    //cout << "r: " << r << endl;

    int ans = (n - r);
    string s;
    for (int i = 0; i < r; ++i) {
      if (a[i] <= q) {
        s += '1';
      } else {
        s += '0';
      }
    }
    for (int i = r; i < n; ++i) {
      s += '1';
    }
    cout << s << "\n";
    //cout << ans << "\n";
  }

private:
    vector<ll> a;

    bool ok(int m, int n, ll q) {
      for (int i = m; i < n; ++i) {
        if (a[i] > q) {
          q--;
        }
      }
      return q >= 0;
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