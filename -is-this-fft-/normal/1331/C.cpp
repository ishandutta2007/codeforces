#include <iostream>

using namespace std;

int main () {
  int a;
  cin >> a;

  int And = (a >> 5) & 1;
  int they = (a >> 4) & 1;
  int lived = (a >> 3) & 1;
  int happily = (a >> 2) & 1;
  int ever = (a >> 1) & 1;
  int after = (a >> 0) & 1;

  int ans = (And << 5) + (after << 4) + (happily << 3) + (lived << 2) + (ever << 1) + they;
  cout << ans << endl;
}