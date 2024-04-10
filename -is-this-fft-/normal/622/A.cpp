#include <iostream>

using namespace std;

int main () {
  long long target;
  cin >> target;

  long long cpos = 1;
  for (int i = 1; true; i++) {
    if (cpos + i <= target) {
      cpos += i;
    } else {
      break;
    }
  }

  cout << target - cpos + 1 << endl;
}