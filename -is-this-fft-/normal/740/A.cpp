#include <iostream>

typedef long long llong;

using namespace std;

int main () {
  llong n, a, b, c;
  cin >> n >> a >> b >> c;

  if (n % 4 == 0) {
    cout << 0 << endl;
  } else if (n % 4 == 3) {
    cout << min(min(b + c, a), 3 * c) << endl;
  } else if (n % 4 == 2) {
    cout << min(min(2 * a, b), 2 * c) << endl;
  } else if (n % 4 == 1) {
    cout << min(min(a + b, 3 * a), c) << endl;
  }
}