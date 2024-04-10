#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  int last = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && t[i] == '0') {
      if (last == 1) {
        ans += 2;
        last = -1;
      } else {
        ans++;
        last = 0;
      }
    } else if (s[i] == '1' && t[i] == '1') {
      if (last == 0) {
        ans++;
        last = -1;
      } else {
        last = 1;
      }
    } else {
      ans += 2;
      last = -1;
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}