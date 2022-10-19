#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  bool win = 0;
  for (int i = 0; i < 5; i++) {
    string t;
    cin >> t;
    if (s[0] == t[0] || s[1] == t[1]) win = 1;
  }
  cout << (win ? "YES" : "NO") << '\n';
}