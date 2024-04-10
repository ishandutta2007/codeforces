#include <iostream>

using namespace std;

void solve () {
  string s;
  cin >> s;

  if ((int) s.size() == 2) {
    cout << s.back() << '\n';
    return;
  }

  char mn = '9';
  for (char c : s) {
    mn = min(mn, c);
  }

  cout << mn << '\n';
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