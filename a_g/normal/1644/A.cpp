#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    bool r = 0;
    bool g = 0;
    bool b = 0;
    bool win = 1;
    for (char c: s) {
      if (c == 'R' && !r) win = 0;
      if (c == 'G' && !g) win = 0;
      if (c == 'B' && !b) win = 0;
      if (c == 'r') r = 1;
      if (c == 'g') g = 1;
      if (c == 'b') b = 1;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}