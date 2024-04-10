#include <iostream>

using namespace std;

int main () {
  int x;
  cin >> x;

  if (x == 3) {
    cout << 5 << endl;
    return 0;
  }

  for (int i = 1; true; i += 2) {
    int mxx = (i * i + 1) / 2;
    if (x <= mxx) {
      cout << i << endl;
      return 0;
    }
  }
}