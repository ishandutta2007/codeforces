#include <iostream>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll dsum (ll x) {
  ll ans = 0;
  while (x != 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

ll gcdsum (ll x) {
  return gcd(x, dsum(x));
}

void solve () {
  ll x;
  cin >> x;

  while (gcdsum(x) == 1) {
    x++;
  }
  cout << x << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}