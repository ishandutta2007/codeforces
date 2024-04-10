#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

map<ll, ll> f;

ll len(ll n) {
  if (n <= 1)
    return 1;

  if (f.count(n))
    return f[n];

  return f[n] = 2 * len(n / 2) + 1;
}

ll fun(ll n, ll pos) {
  if (n <= 1) {
    assert(pos == 0);
    return n;
  }

  ll m = len(n / 2);
  if (pos < m)
    return fun(n / 2, pos);
  else if (pos == m)
    return n % 2;
  else
    return fun(n / 2, pos - (m + 1));
}

ll n, l, r;

void read() {
  cin >> n >> l >> r;
  --l;
}

void kill() {
  ll ans = 0;
  for (ll i = l; i < r; ++i)
    ans += fun(n, i);
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}