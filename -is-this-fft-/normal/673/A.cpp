#include <iostream>

using namespace std;

int main () {
  int interc;
  cin >> interc;

  int last = 0;
  for (int i = 0; i < interc; i++) {
    int minute;
    cin >> minute;
    
    if (minute > last + 15) {
      break;
    }

    last = minute;
  }

  cout << min(90, last + 15) << endl;
}