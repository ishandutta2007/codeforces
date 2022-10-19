#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> cnt(m);
  for (int i = 1; i <= m && i <= n; ++i) {
    int rem = (i * i) % m;
    cnt[rem] += (n - i) / m + 1;
  }

  ll ans = 0;
  for (int i = 1; i <= m && i <= n; ++i) {
    int rem = (i * i) % m;
    int need = (m - rem) % m;
    ll bon = (n - i) / m + 1;
    ans += bon * cnt[need];
  }

  cout << ans << "\n";


}