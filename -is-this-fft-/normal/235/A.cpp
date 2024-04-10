#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll lcm (ll p, ll q) {
  ll gc = gcd(p, q);
  return (p / gc) * q;
}

ll lcm (ll p, ll q, ll r) {
  return lcm(lcm(p, q), r);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  vector<ll> cands;
  for (ll i = max(1LL, n - 5); i <= n; i++) {
    cands.push_back(i);
  }

  ll ans = 0;
  for (auto p : cands) {
    for (auto q : cands) {
      for (auto r : cands) {
        ans = max(ans, lcm(p, q, r));
      }
    }
  }

  cout << ans << endl;
}