#include <iostream>

using namespace std;

int main () {
  int problemc, wayl;
  cin >> problemc >> wayl;

  wayl = 240 - wayl;
  wayl /= 5;

  int ans = 0;
  for (int i = 1; i <= problemc; i++) {
    if ((i * (i + 1)) / 2 <= wayl) {
      ans = i;
    }
  }

  cout << ans << endl;
}