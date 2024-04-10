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

  ll n, k;

  cin >> n >> k;

  ll l, r;

  l = max(1ll, k - n);
  r = min(n, k / 2);

  if (l > r) {
    cout << "0\n";
    return 0;
  }

  ll ans = r - l + 1;
  if (k % 2 == 0 && (k / 2) <= n)
    --ans;

  cout << ans << "\n";
}