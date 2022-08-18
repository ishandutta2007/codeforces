#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int state = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x != 0 && state % 2 == 0) {
      state++;
    }

    if (x == 0 && state % 2 != 0) {
      state++;
    }
  }

  if (state == 0) {
    cout << 0 << '\n';
  } else if (state <= 2) {
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