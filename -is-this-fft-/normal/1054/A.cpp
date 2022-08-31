#include <iostream>

using namespace std;

int main () {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;

  int foot_time = abs(x - y) * t1;
  int el_time = abs(z - x) * t2 + abs(x - y) * t2 + 3 * t3;

  if (el_time <= foot_time) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}