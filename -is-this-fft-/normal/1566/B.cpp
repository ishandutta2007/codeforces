#include <iostream>

using namespace std;

void solve () {
  string s;
  cin >> s;

  bool seen_zero = false, zero_cont = true, last_zero = false;
  for (char c : s) {
    if (c == '0') {
      if (!seen_zero) {
        seen_zero = true;
      } else if (seen_zero && !last_zero) {
        zero_cont = false;
      }
    }

    last_zero = c == '0';
  }

  if (!seen_zero) {
    cout << 0 << '\n';
  } else if (zero_cont) {
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