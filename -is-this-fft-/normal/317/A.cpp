#include <iostream>

typedef long long ll;

using namespace std;

int main () {
  ll x, y, m;
  cin >> x >> y >> m;

  if (max(x, y) >= m) {
    cout << 0 << '\n';
    return 0;
  }

  if (max(x, y) <= 0) {
    cout << -1 << '\n';
    return 0;
  }

  ll ans = 0;
  while (max(x, y) < m) {
    if (x > y) {
      swap(x, y);
    }

    if (x < 0) {
      ll k = (-x + y - 1) / y;
      x += y * k;
      ans += k;
    } else {
      x += y;
      ans++;
    }
  }

  cout << ans << endl;
}