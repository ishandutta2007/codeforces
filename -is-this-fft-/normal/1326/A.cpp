#include <iostream>

using namespace std;

void solve () {
  int n;

  cin >> n;

  if (n == 1) {
    cout << -1 << '\n';
    return;
  }

  if ((n - 1) % 3 == 0) {
    for (int i = 0; i < n - 2; i++) {
      cout << 2;
    }
    cout << 33 << '\n';
  } else {
    for (int i = 0; i < n - 1; i++) {
      cout << 2;
    }
    cout << 3 << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}