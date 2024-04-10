#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    char pr = 'x';
    int len = 0;
    bool win = 1;
    for (char c: s) {
      if (c != pr) {
        if (len == 1) win = 0;
        pr = c;
        len = 1;
      }
      else {
        len++;
      }
    }
    if (len == 1) win = 0;
    cout << (win ? "YES" : "NO") << '\n';
  }
}