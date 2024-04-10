#include <iostream>

using namespace std;

int main () {
  string s, t;
  cin >> s >> t;

  int c01 = 0, c10 = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '4' && t[i] == '7') {
      c01++;
    } else if (s[i] == '7' && t[i] == '4') {
      c10++;
    }
  }

  cout << max(c01, c10) << '\n';
}