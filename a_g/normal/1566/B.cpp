#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    bool group = false;
    bool endgroup = false;
    bool secondgroup = false;
    for (char c: s) {
      if (c == '0') {
        group = true;
        if (endgroup) {
          secondgroup = true;
        }
      }
      if (c == '1' && group) {
        endgroup = true;
      }
    }
    if (!group) {
      cout << 0 << endl;
    }
    else if (secondgroup) {
      cout << 2 << endl;
    }
    else {
      cout << 1 << endl;
    }
  }
}