#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    x -= min(x, a);
    y -= min(y, b);
    cout << (c >= x+y ? "YES" : "NO") << '\n';
  }
}