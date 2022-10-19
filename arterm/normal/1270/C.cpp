#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    
    ll x = 0;
    ll s = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
      ll a;
      cin >> a;
      x ^= a;
      s += a;
    }

    cout << "2\n";
    cout << x << " " << s + x << "\n";
  }
}