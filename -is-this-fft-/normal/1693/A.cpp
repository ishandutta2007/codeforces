#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  bool fail = false, zro = false;
  ll bal = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    bal += x;
    if (bal < 0) {
      fail = true;
    }

    if (bal == 0) {
      zro = true;
    }

    if (bal > 0 && zro) {
      fail = true;
    }
  }

  if (bal != 0) {
    fail = true;
  }

  cout << (fail ? "NO" : "YES") << '\n';
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