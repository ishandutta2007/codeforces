#include <iostream>
#include <algorithm>

using namespace std;

void solve () {
  string s;
  cin >> s;

  int tot = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    char c = s[i];
    tot += c - 'a' + 1;
  }

  if ((int) s.size() % 2 == 1) {
    tot -= 2 * (min(s[0], s.back()) - 'a' + 1);
  }

  if (tot < 0) {
    cout << "Bob " << -tot << '\n';
  } else {
    cout << "Alice " << tot << '\n';
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