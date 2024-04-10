#include <iostream>

using namespace std;

struct point {
  int x, y;
  
  point () {
    x = 0;
    y = 0;
  }
};

int main () {
  point a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  
  if ((a.x == b.x && b.x == c.x) || (a.y == b.y && b.y == c.y)) {
    cout << 1 << endl;
  } else if (((a.x == b.x) && ((c.y <= min(a.y, b.y)) || (c.y >= max(a.y, b.y)))) ||
	     ((a.x == c.x) && ((b.y <= min(a.y, c.y)) || (b.y >= max(a.y, c.y)))) ||
	     ((b.x == c.x) && ((a.y <= min(b.y, c.y)) || (a.y >= max(b.y, c.y)))) ||
	     ((a.y == b.y) && ((c.x <= min(a.x, b.x)) || (c.x >= max(a.x, b.x)))) ||
	     ((a.y == c.y) && ((b.x <= min(a.x, c.x)) || (b.x >= max(a.x, c.x)))) ||
	     ((b.y == c.y) && ((a.x <= min(b.x, c.x)) || (a.x >= max(b.x, c.x))))) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }
}