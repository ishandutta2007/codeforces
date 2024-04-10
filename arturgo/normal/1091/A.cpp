#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int yellow, blue, red;
  cin >> yellow >> blue >> red;

  cout << 3 * min(min(yellow + 1, blue), red - 1) << endl;
  return 0;
}