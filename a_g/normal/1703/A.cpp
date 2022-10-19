#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    bool good = 1;
    if (s[0] != 'Y' && s[0] != 'y') good = 0;
    if (s[1] != 'E' && s[1] != 'e') good = 0;
    if (s[2] != 'S' && s[2] != 's') good = 0;
    cout << (good ? "YES" : "NO") << '\n';
  }
}