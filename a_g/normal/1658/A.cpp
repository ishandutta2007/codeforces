#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pre = -5;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (pre == i-1) ans += 2;
        if (pre == i-2) ans += 1;
        pre = i;
      }
    }
    cout << ans << '\n';
  }
}