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
    ll a, b, c;
    cin >> a >> b >> c;
    ll k = 1e9;
    ll x = a + b + k * c;
    ll y = b + k * c;
    ll z = c;
    assert(x % y == a);
    assert(y % z == b);
    assert(z % x == c);
    cout << x << " " << y << " " << z << "\n";
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