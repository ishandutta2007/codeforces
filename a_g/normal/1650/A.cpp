#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    char c;
    cin >> s >> c;
    bool win = 0;
    for (int i = 0; i < s.length(); i += 2) {
      if (s[i] == c) win = 1;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}