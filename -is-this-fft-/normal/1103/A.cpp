#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
  string str;
  cin >> str;

  int vp = 0;
  int hp = 0;
  for (char c : str) {
    if (c == '0') {
      cout << 1 << " " << vp + 1 << '\n';
      vp += 1;
      vp %= 4;
    } else {
      cout << 3 << " " << 1 + 2 * hp << '\n';
      hp += 1;
      hp %= 2;
    }
  }
}