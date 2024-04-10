#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    string s;
    cin >> n >> q >> s;
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      bool ok = 0;
      for (int i = 0; i < l; i++) {
        if (s[i] == s[l]) ok = 1;
      }
      for (int i = r+1; i < n; i++) {
        if (s[i] == s[r]) ok = 1;
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }
}