#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;

  int length = (int) s.size();

  s += s;
  int ans = 1, cur = 1;
  for (int i = 1; i < (int) s.size(); i++) {
    if (s[i] != s[i - 1]) {
      cur++;
    } else {
      cur = 1;
    }

    ans = max(cur, ans);
  }

  ans = min(ans, length);
  cout << ans << endl;
}