#include <iostream>

using namespace std;

int main () {
  int length;
  cin >> length;
  
  if (length % 2 == 1) {
    cout << 0 << endl;
  } else {
    length /= 2;
    if (length % 2 == 1) {
      cout << length / 2 << endl;
    } else {
      cout << length / 2 - 1 << endl;
    }
  }
}