#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, d, e;

int main() {
  cin >> n >> d >> e; e *= 5;
  ll ans = n;
  for (ll i = 0; i <= d; ++i) {
    ll took = i * e;
    if (took > n) break;
    ll rem = n - took;
    ans = min(ans, rem % d);
  }
  cout << ans << '\n';
  return 0;
}