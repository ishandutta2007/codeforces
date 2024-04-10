#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  int d, m;
  cin >> d >> m;
  
  ll ans = 1;

  int last = 0;
  for (int i = 1; i <= 30; i++) {
    if (((1 << i) - 1) < d) {
      ans += ans * (((1 << i) - 1) - last);
      ans %= m;
    } else {
      ans += ans * (d - last);
      ans %= m;
      break;
    }

    last = (1 << i) - 1;
  }

  ans += (m - 1);
  ans %= m;
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}