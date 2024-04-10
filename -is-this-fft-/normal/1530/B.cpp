#include <iostream>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  // first row
  cout << '1';
  for (int j = 1; j < m - 1; j++) {
    if (j % 2 == 0 && j + 1 != m - 1) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << '1';
  cout << '\n';

  for (int i = 1; i < n - 1; i++) {
    if (i % 2 == 0 && i + 1 != n - 1) {
      cout << 1;
    } else {
      cout << 0;
    }

    for (int j = 1; j < m - 1; j++) {
      cout << 0;
    }

    if (i % 2 == 0 && i + 1 != n - 1) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << '\n';
  }

  // last row
  cout << '1';
  for (int j = 1; j < m - 1; j++) {
    if (j % 2 == 0 && j + 1 != m - 1) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << '1';
  cout << '\n';
  cout << '\n';
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