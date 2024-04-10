#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

ll gcd(ll x, ll y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {

    ll p, q, b;
    cin >> p >> q >> b;
    
    ll g = gcd(p, q);
    q /= g;

    g = b;

    while ((g = gcd(q, g)) > 1) {
      q /= g;
    }

    if (q == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }
}