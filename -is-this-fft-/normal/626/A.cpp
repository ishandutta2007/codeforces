#include <iostream>

const int MAX_O = 205;

using namespace std;

char order [MAX_O];

int main () {
  int orderc;

  cin >> orderc;
  for (int i = 0; i < orderc; i++) {
    cin >> order[i];
  }

  int count = 0, xpos = 0, ypos = 0;
  for (int i = 0; i < orderc; i++) {
    xpos = 0;
    ypos = 0;
    for (int j = i; j < orderc; j++) {
      if (order[j] == 'U') {
	ypos--;
      } else if (order[j] == 'D') {
	ypos++;
      } else if (order[j] == 'R') {
	xpos++;
      } else if (order[j] == 'L') {
	xpos--;
      }

      if (xpos == 0 && ypos == 0) {
	count++;
      }
    }
  }

  cout << count << endl;
}