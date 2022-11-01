#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t; ll a, b;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    ll ans = max(min(a / 2, b), min(a, b / 2));
    for (ll i = a; i >= max(0LL, a - 69); --i) {
      for (ll j = b; j >= max(0LL, b - 69); --j) {
        // 2x + y = i, 2y + x = j
        if ((i + j) % 3) continue;
        ll sum = (i + j) / 3;
        ll x = i - sum, y = j - sum;
        if (x >= 0 and y >= 0) ans = max(ans, x + y);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}