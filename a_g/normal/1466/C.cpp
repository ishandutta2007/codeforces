#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i-1] || (i > 1 && s[i] == s[i-2])) {
        s[i] = ' ';
        ans++;
      }
    }
    cout << ans << '\n';
  }
}