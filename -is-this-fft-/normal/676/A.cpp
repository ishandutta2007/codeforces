#include <iostream>

using namespace std;

int main () {
  int spos, lpos;
  int length;
  cin >> length;
  
  for (int i = 0; i < length; i++) {
    int num;
    cin >> num;

    if (num == 1) {
      spos = i;
    }

    if (num == length) {
      lpos = i;
    }
  }

  if (min(spos, lpos) == 0 ||
      max(spos, lpos) == length - 1) {
    cout << length - 1 << endl;
  } else {
    cout << max(max(spos - 0, lpos - 0),
                max(length - 1 - spos, length - 1 - lpos)) << endl;
  }
}