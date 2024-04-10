#include <iostream>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll ffrac (ll p, ll q) {
  return p / q;
}

ll cfrac (ll p, ll q) {
  return (p + q - 1) / q;
}

int main () {
  ll la, ra, ta;
  cin >> la >> ra >> ta;

  ll lb, rb, tb;
  cin >> lb >> rb >> tb;

  if (lb < la) {
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }

  ll ans = -1;
  ll gc = gcd(ta, tb);
  ll k = ffrac(lb - la, gc);
  ans = max(ans, max(min(ra + k * gc, rb) - max(la + k * gc, lb) + 1, 0LL));
  k = cfrac(lb - la, gc);
  ans = max(ans, max(min(ra + k * gc, rb) - max(la + k * gc, lb) + 1, 0LL));
  cout << ans << endl;
}