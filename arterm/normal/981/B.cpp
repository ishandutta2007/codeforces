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


  map<ll, ll> w;

  for (int iter = 0; iter < 2; ++iter) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      ll x, y;
      cin >> x >> y;
      w[x] = max(w[x], y);
    }
  }

  ll ans = 0;
  for (auto p : w)
    ans += p.second;

  cout << ans << endl;
}