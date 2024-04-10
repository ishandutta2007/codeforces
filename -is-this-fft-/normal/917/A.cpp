#include <iostream>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l = 0, r = 0, flag = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == '(') {
        l++; r++;
      } else if (s[j] == ')') {
        if (r == 0) flag = 1;
        l = max(0, l - 1);
        r = max(0, r - 1);
      } else if (s[j] == '?') {
        l = max(0, l - 1);
        r++;
      }

      if ((j - i) % 2 == 1) {
        if (l == 0 && !flag) ans++;
      }
    }
  }

  cout << ans << endl;
}