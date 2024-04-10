#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int l = n / 2;
  int r = n / 2;

  while (l > 0) {
    if (s[l - 1] == s[l]) {
      l--;
    } else {
      break;
    }
  }

  while (r < n - 1) {
    if (s[r + 1] == s[r]) {
      r++;
    } else {
      break;
    }
  }

  cout << r - l + 1 << '\n';
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