#include <iostream>
#include <string>

using namespace std;

int main () {
  int length, target;
  cin >> length >> target;

  string orig;
  cin >> orig;

  string ans ("");
  int uc = 0, cs = 0;

  for (char c : orig) {
    if (c == '(') {
      if (uc < target / 2) {
        ans += c;
        uc++;
        cs++;
      }
    } else if (c == ')') {
      if (cs > 0) {
        ans += c;
        cs--;
      }
    }
  }

  cout << ans << endl;
}