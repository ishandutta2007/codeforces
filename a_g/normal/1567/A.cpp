#include <bits/stdc++.h>
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    for (char c: s) {
      if (c == 'U') {
        cout << 'D';
      }
      else if (c == 'D') {
        cout << 'U';
      }
      else {
        cout << c;
      }
    }
    cout << endl;
  }
}