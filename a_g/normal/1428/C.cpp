#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int b = 0;
    int ans = 0;
    while (s.size()) {
      if (s.back() == 'A') {
        if (b) b--;
        else ans++;
      }
      else {
        b++;
      }
      s.pop_back();
    }
    ans += (b&1);
    cout << ans << '\n';
  }
}