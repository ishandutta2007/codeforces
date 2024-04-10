#include <iostream>
#include <algorithm>

typedef long long llong;

using namespace std;

int main () {
  llong xl, yl, xh, yh;
  cin >> xl >> yl >> xh >> yh;

  if (abs(xl % 2) != abs(yl % 2)) {
    yl--;
    yh--;
  }
  
  llong oddh = ((yh % 2 == 0 ? yh - 1 : yh) -
		(yl % 2 == 0 ? yl + 1 : yl)) / 2 + 1;
  llong oddw = ((xh % 2 == 0 ? xh - 1 : xh) -
		(xl % 2 == 0 ? xl + 1 : xl)) / 2 + 1;
  llong eveh = ((yh % 2 != 0 ? yh - 1 : yh) -
		(yl % 2 != 0 ? yl + 1 : yl)) / 2 + 1;
  llong evew = ((xh % 2 != 0 ? xh - 1 : xh) -
		(xl % 2 != 0 ? xl + 1 : xl)) / 2 + 1;

  cout << oddh * oddw + eveh * evew << endl;
}