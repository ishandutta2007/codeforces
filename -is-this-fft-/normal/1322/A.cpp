#include <iostream>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int bal = 0, ans = 0;
  for (char c : s) {
    if (c == '(') {
      if (bal < 0) ans++;
      bal++;
    } else {
      if (bal <= 0) ans++;
      bal--;
    }
  }

  if (bal != 0) cout << -1 << endl;
  else cout << ans << endl;
}