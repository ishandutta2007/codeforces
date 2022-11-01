#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll getpw(ll x, ll p) {
  ll ans = 1;
  while (x % p == 0) {
    ans *= p;
    x /= p;
  }
  return ans;
}

void solve() {
  ll q, p;
  cin >> p >> q;
  if (p % q) {
    cout << p << "\n";
    return;
  }

  vector<ll> primes;
  ll q1 = q;
  while (q1 > 1) {
    bool fnd = false;
    for (ll i = 2; i * i <= q1; ++i) {
      if (q1 % i == 0) {
        fnd = true;
        primes.push_back(i);
        while (q1 % i == 0) q1 /= i;
      }
    }
    if (!fnd) {
      if (q1 > 1) {
        primes.push_back(q1);
        q1 = 1;
      }
    }
  }

  ll ans = 0;
  for (auto pr: primes) {
    ans = max(ans, p / getpw(p, pr) * getpw(q, pr) / pr);
  }
  cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}