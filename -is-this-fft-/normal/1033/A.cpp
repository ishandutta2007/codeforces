#include <iostream>

using namespace std;

int queenx, queeny;

int reg (int x, int y) {
  int ans = 0;
  ans <<= 1;
  ans += (x < queenx);
  ans <<= 1;
  ans += (y < queeny);
  return ans;
}

int main () {
  int dims;
  cin >> dims;

  cin >> queenx >> queeny;
  int bx, by, cx, cy;
  cin >> bx >> by >> cx >> cy;

  if (reg(bx, by) != reg(cx, cy)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}