#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int ans = 10;
    for (int z = 0; z < 2; z++) {
      int pts[2] = {0, 0};
      int rem[2] = {5, 5};
      for (int i = 0; i < 10; i++) {
        if (s[i] == '1' || (s[i] == '?' && (i&1)==z)) {
          pts[i&1]++;
        }
        rem[i&1]--;
        if (pts[z] > pts[1-z] + rem[1-z]) {
          ans = min(ans, i+1);
          break;
        }
      }
    }

    cout << ans << '\n';
  }
}