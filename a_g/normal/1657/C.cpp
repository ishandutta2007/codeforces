#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int c = 0;
    int r = n;
    string t;
    for (char z: s) {
      if (t.empty()) {
        t.push_back(z);
        continue;
      }
      if (t[0] == '(') {
        c++;
        r-=2;
        t.clear();
        continue;
      }
      t.push_back(z);
      if (z == ')') {
        c++;
        r-=t.size();
        t.clear();
        continue;
      }
    }
    cout << c << " " << r << '\n';
  }
}