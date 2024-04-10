#include <bits/stdc++.h>

using namespace std;

int t;
long long x[2], y[2], z[2];

int main() {
  cin >> t;
  while (t--) {
    cin >> x[0] >> y[0] >> z[0];
    cin >> x[1] >> y[1] >> z[1];
    long long ans = 0, mn = min(z[0], y[1]);
    ans += 2 * mn, z[0] -= mn, y[1] -= mn;
    if (x[1] + y[1] < y[0]) ans -= 2 * (y[0] - x[1] - y[1]);
    cout << ans << '\n';
  }
  return 0;
}

// 222222222211111111111
//    11111110000000