#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll gcd(ll a, ll b) {
  if (b < 0) {
    return gcd(a, -b);
  }
  if (a < b) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(a-(a/b)*b, b);
}

ll lcm(ll a, ll b) {
  return a*b/gcd(a, b);
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    ll m = 1;
    ll k = 1;
    ll ans = 0;
    while (m <= n) {
      ans += (n/m) % MOD;
      ans %= MOD;
      m = lcm(m, k);
      k++;
    }
    cout << ans << endl;
  }
}