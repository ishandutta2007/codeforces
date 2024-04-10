#include <iostream>

using namespace std;

int main () {
  int n, m;
  cin >> n >> m;

  if (m == 0) {
    cout << 1 << endl;
  } else if (2 * m <= n) {
    cout << m << endl;
  } else {
    cout << n - m << endl;
  }
}