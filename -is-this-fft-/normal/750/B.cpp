#include <iostream>
#include <string>

using namespace std;

int main () {
  int dirc;
  cin >> dirc;

  int pos = 0;
  for (int i = 0; i < dirc; i++) {
    int length;
    string dir;
    
    cin >> length >> dir;
    if (pos == 0 && dir != "South") {
      cout << "NO" << endl;
      return 0;
    } else if (pos == 20000 && dir != "North") {
      cout << "NO" << endl;
      return 0;
    }

    if (dir == "North") {
      pos -= length;
    } else if (dir == "South") {
      pos += length;
    }

    if (pos < 0 || pos > 20000) {
      cout << "NO" << endl;
      return 0;
    }
  }

  if (pos != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}