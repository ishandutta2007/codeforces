#include <iostream>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 1) {
    cout << 0 << '\n';
  } else if (n == 1 || m == 1) {
    cout << 1 << '\n';
  } else {
    cout << 2 << '\n';
  }
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