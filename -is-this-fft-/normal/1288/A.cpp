#include <iostream>

using namespace std;

typedef long long ll;

ll ceil (ll a, ll b) {
  return (a + b - 1) / b;
}

ll tryw (ll n, ll d, ll x) {
  if (x < 0 || n <= x) {
    return false;
  }

  return x + ceil(d, x + 1) <= n;
}

void solve () {
  ll n, d;
  cin >> n >> d;

  if (tryw(n, d, (n - 1) / 2)) {
    cout << "YES" << '\n';
    return;
  }

  if (tryw(n, d, n / 2)) {
    cout << "YES" << '\n';
    return;
  }

  cout << "NO" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int t = 0; t < testc; t++) {
    solve();
  }
}