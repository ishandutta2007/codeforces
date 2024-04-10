#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  ll ans = abs(x2 - x1) + abs(y2 - y1);
  if (y1 != y2 && x1 != x2) {
    ans += 2;
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  
  for (int t = 0; t < testc; t++) {
    solve();
  }
}