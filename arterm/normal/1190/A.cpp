#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
    --p[i];
  }

  p.push_back(n + k + 10);

  ll ans = 0;

  ll drop = 0;

  for (int i = 0; i <= m; ++i) {
    if ((p[i] - drop) / k > (p[drop] - drop) / k) {
      ++ans;
      drop = i;
    }
  }

  cout << ans << "\n";
}