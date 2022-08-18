#include <iostream>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

void solve () {
  ll p, q, b;
  cin >> p >> q >> b;

  q /= gcd(p, q);

  while (true) {
    ll gc = gcd(q, b);
    if (gc == 1) break;
    while (q % gc == 0) {
      q /= gc;
    }
  }
  
  if (q == 1) {
    cout << "Finite" << '\n';
  } else {
    cout << "Infinite" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    solve();
  }
}