#include <iostream>

using namespace std;

int main () {
  int repc, height, width;
  cin >> repc >> height >> width;

  if (repc > height * width) {
    cout << "-1" << endl;
  } else {
    int democrat = 1, republican = 2;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
	if ((i + j) % 2 == 0) {
	  if (democrat > repc) {
	    cout << 0;
	  } else {
	    cout << democrat;
	    democrat += 2;
	  }
	} else {
	  if (republican > repc) {
	    cout << 0;
	  } else {
	    cout << republican;
	    republican += 2;
	  }
	}
	cout << (j == width - 1 ? '\n' : ' ');
      }
    }
  }
}