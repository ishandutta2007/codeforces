#include <iostream>
#include <vector>

using namespace std;

int main () {
  int rotc;
  cin >> rotc;

  vector<int> rots (rotc);
  for (int i = 0; i < rotc; i++) {
    cin >> rots[i];
  }

  for (int k = 0; k < 1 << rotc; k++) {
    int cur = 0;
    for (int i = 0; i < rotc; i++) {
      if (k & 1 << i) {
        cur += rots[i];
      } else {
        cur -= rots[i];
      }
    }

    if (cur % 360 == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}