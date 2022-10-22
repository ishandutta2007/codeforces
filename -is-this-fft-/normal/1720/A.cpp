#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll l = a * d, r = b * c;
  
  if (l == r) {
    cout << 0 << '\n';
    return;
  }

  if (l == 0 || r == 0 || l % r == 0 || r % l == 0) {
    cout << 1 << '\n';
    return;
  }
  
  cout << 2 << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}