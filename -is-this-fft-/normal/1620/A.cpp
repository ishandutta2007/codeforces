#include <iostream>

using namespace std;

void solve () {
  string s;
  cin >> s;

  int cn = 0;
  for (char c : s) {
    if (c == 'N') cn++;
  }

  if (cn == 1) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
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