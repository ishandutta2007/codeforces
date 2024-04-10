#include <iostream>

using namespace std;

typedef long long ll;

ll upto (ll k) {
  return k * (k + 1) - k;
}

void solve () {
  ll n, k;
  cin >> n >> k;

  ll lb = upto(k);
  if (n < lb) {
    cout << "NO" << '\n';
    return;
  }
  if ((n - lb) % 2 == 1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int t = 1; t <= testc; t++) {
    solve();
  }
}