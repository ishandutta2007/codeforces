#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    string s, t;
    cin >> n >> x >> y >> s >> t;
    vector<int> a;
    int m = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        a.push_back(i);
        m++;
      }
    }
    if (m%2 != 0) {
      cout << "-1\n";
      continue;
    }
    if (m != 2) {
      cout << 1LL*m*y/2 << '\n';
      continue;
    }
    if (a[0]+1 == a[1]) {
      if (a[0] > 1 || a[1] < n-2) {
        cout << min(x, 2*y) << '\n';
      }
      else {
        cout << x << '\n';
      }
    }
    else {
      cout << y << '\n';
    }
  }
}