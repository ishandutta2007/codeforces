#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s[0] == 'B' || s.back() == 'A') {
      cout << "NO\n";
      continue;
    }
    bool win = 1;
    int x = 0;
    for (char c: s) {
      if (c == 'A') x++;
      else x--;
      if (x < 0) win = 0;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}