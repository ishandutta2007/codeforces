#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

int t;
ll x, y, p, q;

int main (int argc, char const *argv[]) {
  cin >> t; while (t--) {
    cin >> x >> y >> p >> q;
    if (p == q) {
      if (x == y) {
        puts("0");
      } else {
        puts("-1");
      }
    } else if (p == 0) {
      if (x == 0) {
        puts("0");
      } else {
        puts("-1");
      }
    } else {
      ll up1 = (x + p - 1)/p;
      ll up2 = (y - x + q - p - 1)/(q - p);
      ll s = max(up1, up2);
      ll up3 = (y + q - 1)/q;
      s = max(s, up3);
      ll ans = q * s - y;
      cout << ans << '\n';
    }
  }
  return 0;
}