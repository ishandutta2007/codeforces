#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int r = 0;
    int evens = 0;
    bool haszero = 0;
    for (char c: s) {
      int d = c-'0';
      if (d%2 == 0) evens++;
      if (d == 0) haszero = 1;
      r = (r+d)%3;
    }
    cout << ((r == 0 && evens >= 2 && haszero || s == "0") ? "red" : "cyan") << '\n';
  }
}