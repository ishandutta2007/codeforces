#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int pos = n - 1; // mirror after this pos
  bool stat = true;
  for (int i = 0; i < n - 1; i++) {
    if (s[i + 1] > s[i]) {
      pos = i;
      break;
    } else if (s[i + 1] < s[i]) {
      stat = false;
    } else {
      // equal
      if (stat) {
        pos = i;
        break;
      }
    }
  }

  for (int i = 0; i <= pos; i++) {
    cout << s[i];
  }

  for (int i = pos; i >= 0; i--) {
    cout << s[i];
  }
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