#include <iostream>
#include <cmath>

using namespace std;

int xcoord [4], ycoord [4];

int area (int a, int b) {
  return abs(xcoord[a]-xcoord[b])*abs(ycoord[a]-ycoord[b]);
}

int main () {
  int verticec;
  cin >> verticec;
  for (int i = 0; i < verticec; i++) {
    cin >> xcoord[i] >> ycoord[i];
  }

  if (verticec == 1) {
    cout << -1 << endl;
  } else if (verticec == 2) {
    if (xcoord[0] == xcoord[1] ||
	ycoord[0] == ycoord[1]) {
      cout << -1 << endl;
    } else {
      cout << area(0, 1) << endl;
    }
  } else if (verticec == 3) {
    if (area(0, 1)) cout << area(0, 1) << endl;
    else if (area(0, 2)) cout << area(0, 2) << endl;
    else cout << area(1, 2) << endl;
  } else {
    if (area(0, 1)) cout << area(0, 1) << endl;
    else if (area(0, 2)) cout << area(0, 2) << endl;
    else if (area(0, 3)) cout << area(0, 3) << endl;
    else if (area(1, 2)) cout << area(1, 2) << endl;
    else if (area(1, 3)) cout << area(1, 3) << endl;
    else cout << area(2, 3) << endl;
  }
}