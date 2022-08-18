#include <iostream>
#include <math.h>

using namespace std;

typedef long double ldouble;

const ldouble EPS = 0.0000001;

ldouble dist (ldouble x1, ldouble y1, ldouble x2, ldouble y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main () {
  int radius, x1, y1, x2, y2;
  cin >> radius >> x1 >> y1 >> x2 >> y2;

  cout << (int) ceil(dist(x1, y1, x2, y2) / (2 * (ldouble) radius)) << endl;
}