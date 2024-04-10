#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {

    ll a, b;

    cin >> a >> b;
    
    if (b != a - 1) {
      cout << "NO\n";
      continue;
    }

    ll x = a + b;

    bool ok = true;
    for (ll i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}