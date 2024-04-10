#include <iostream>

typedef long long llong;

using namespace std;

int main () {
  int cowc, napl;
  cin >> cowc >> napl;

  int max_swap = cowc / 2;
  llong ans = 0;
  for (int i = 0; i < min(max_swap, napl); i++) {
    ans += cowc - 1;
    ans += cowc - 2;
    cowc -= 2;
  }
  cout << ans << endl;
}