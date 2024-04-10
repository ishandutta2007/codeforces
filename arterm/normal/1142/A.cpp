#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

ll mabs(ll x) {
  return x < 0 ? -x : x;
}

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

  ll n, k;
  cin >> n >> k;
  ll a, b;
  cin >> a >> b;


  ll mn = n * k;
  ll mx = 0;
 
  for (ll x : {-a, +a}) {
    for (ll y : {-b, +b}) {
      ll d = y - x;
      d = mabs(d);

      ll by = gcd(k, d);
      
      ll rk = k / by;
      ll rn = n;
      while (gcd(rk, rn) > 1) {
        rn /= gcd(rk, rn);
      }

      //cerr << "d = " << d << ", by = " << by << ", rk = " << rk << "\n";
      //cerr << "gn = " << gn << "!\n";
      //cerr << "\n";
      
      mn = min(mn, (n / rn) * k / by);
      mx = max(mx, (n * k) / by);
    }
  }

  cout << mn << " " << mx << "\n";

}