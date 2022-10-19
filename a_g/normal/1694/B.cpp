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
    long long ans = 0;
    for (int r = 0; r < n; r++) {
      if (r == 0 || s[r] != s[r-1]) {
        ans += r+1;
      }
      else {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
}