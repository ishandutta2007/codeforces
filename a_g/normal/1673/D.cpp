#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int b, q, y, c, r, z;
    cin >> b >> q >> y >> c >> r >> z;
    if (r % q != 0) {
      cout << "0\n";
      continue;
    }
    if ((c%q+q)%q != (b%q+q)%q) {
      cout << "0\n";
      continue;
    }
    if (c < b || c+1LL*(z-1)*r > b+1LL*(y-1)*q) {
      cout << "0\n";
      continue;
    }
    if (c-r < b || c+1LL*z*r > b+1LL*(y-1)*q) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    auto calc = [&] (int d) {
      if (1LL*d*q/__gcd(d, q) != r) {
        return 0LL;
      }
      return 1LL * (r/d)*(r/d) % MOD;
    };
    for (int d = 1; d*d <= r; d++) {
      if (r%d == 0) {
        ans = (ans+calc(d))%MOD;
        if (r/d > d) {
          ans = (ans+calc(r/d))%MOD;
        }
      }
    }
    cout << ans << '\n';
  }
}