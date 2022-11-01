#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t; ll n, l, r;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    ll tot = 0, at = 1;
    while (tot + (at < n ? 2 * (n - at) : 1) < l) {
      tot += (at < n ? 2 * (n - at) : 1), ++at;
    }
    vector <ll> cur;
    l -= tot, r -= tot;
    while (cur.size() < r) {
      if (at == n) {
        cur.emplace_back(1);
        break;
      }
      for (ll i = at + 1; i <= n; ++i) {
        cur.emplace_back(at); 
        cur.emplace_back(i);
      } ++at;
    }
    for (ll i = l; i <= r; ++i) {
      printf("%lld ", cur[i - 1]);
    }
    puts("");
  }
  return 0;
}