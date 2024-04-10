#include <iostream>

using namespace std;

int main () {
  int twoc, threec;
  cin >> twoc >> threec;
  
  long long init2 = 2 * twoc, init3 = 3 * threec;
  for (int i = 6; i <= min(init2, init3); i += 6) {
    if (init2 + 2 < init3 + 3) {
      init2 += 2;
    } else {
      init3 += 3;
    }
  }

  cout << max(init2, init3) << endl;
}