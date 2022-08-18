#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll n;
  cin >> n;

  if (n % 2 == 1) {
    cout << -1 << '\n';
    return;
  }

  n /= 2;
  if (n == 1) {
    cout << -1 << '\n';
    return;
  }

  ll mn = 0, mx = 0;
  {
    ll cur = n;
    // assume most 3-wheel
    while (cur % 3 != 0) {
      cur -= 2;
      mn++;
    }
    mn += cur / 3;
  }

  {
    ll cur = n;
    while (cur % 2 != 0) {
      cur -= 3;
      mx++;
    }
    mx += cur / 2;
  }

  cout << mn << " " << mx << '\n';
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