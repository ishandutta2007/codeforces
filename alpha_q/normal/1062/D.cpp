#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

ll n, ans;

int main() {
  cin >> n;
  for (ll i = 2; i <= n; ++i) {
    for (ll j = i + i; j <= n; j += i) {
      ans += (4 * j / i);
    }
  }
  cout << ans << '\n';
  return 0;
}