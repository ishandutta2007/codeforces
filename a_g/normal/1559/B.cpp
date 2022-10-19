#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char current = 'R';
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        current = (i&1) ? 'B'+'R'-s[i] : s[i];
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') s[i] = current;
      else current = s[i];
      current = 'R' + 'B' - current;
    }
    cout << s << endl;
  }
}