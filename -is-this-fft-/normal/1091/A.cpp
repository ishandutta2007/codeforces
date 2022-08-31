#include <iostream>

using namespace std;

int main () {
  int y, b, r;
  cin >> y >> b >> r;

  int mid = y + 1;
  mid = min(mid, b);
  mid = min(mid, r - 1);

  cout << 3 * mid << endl;
}