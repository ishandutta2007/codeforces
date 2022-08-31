#include <iostream>

using namespace std;

int main () {
  int rcount = 0, bcount = 0, gcount = 0;
  int cardc;
  cin >> cardc;

  char c;
  for (int i = 0; i < cardc; i++) {
    cin >> c;
    if (c == 'R') {
      rcount++;
    } else if (c == 'B') {
      bcount++;
    } else if (c == 'G') {
      gcount++;
    }
  }

  if (rcount && gcount && bcount) {
    cout << "BGR" << endl;
  } else if (rcount && !gcount && !bcount) {
    cout << "R" << endl;
  } else if (!rcount && gcount && !bcount) {
    cout << "G" << endl;
  } else if (!rcount && !gcount && bcount) {
    cout << "B" << endl;
  } else if (rcount == 1 && gcount == 1 && !bcount) {
    cout << "B" << endl;
  } else if (rcount == 1 && !gcount && bcount == 1) {
    cout << "G" << endl;
  } else if (!rcount && gcount == 1 && bcount == 1) {
    cout << "R" << endl;
  } else {
    int mttc = (rcount > 1) + (bcount > 1) + (gcount > 1);
    if (mttc == 2) {
      cout << "BGR" << endl;
    } else {
      if (rcount > 1) {
	cout << "BG" << endl;
      } else if (gcount > 1) {
	cout << "BR" << endl;
      } else {
	cout << "GR" << endl;
      }
    }
  }
}