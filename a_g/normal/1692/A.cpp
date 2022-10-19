#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int z: {b, c, d}) {
      if (z > a) ans++;
    }
    cout << ans << '\n';
  }
}