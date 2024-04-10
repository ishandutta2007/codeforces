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
    if (n&1) {
      int ans = 1;
      char c = s[n/2];
      for (int i = 1; i <= n/2; i++) {
        if (s[n/2-i] == c) {
          ans += 2;
        }
        else {
          break;
        }
      }
      cout << ans << '\n';
    }

    else {
      int ans = 2;
      char c = s[n/2];
      for (int i = 1; i < n/2; i++) {
        if (s[n/2+i] == c) {
          ans += 2;
        }
        else {
          break;
        }
      }
      cout << ans << '\n';
    }
  }
}