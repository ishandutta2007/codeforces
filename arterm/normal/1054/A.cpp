#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

ll mabs(ll x) {
  if (x < 0) return -x;
  return x;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ll x, y, z, t1, t2, t3;

  cin >> x >> y >> z >> t1 >> t2 >> t3;

  ll stairs = mabs(x - y) * t1;
  ll elev = mabs(x - z) * t2 + mabs(x - y) * t2 + 3 * t3;

  //cerr << stairs << " " << elev << "\n";

  if (stairs < elev) 
    cout << "NO\n";
  else
    cout << "YES\n";

}