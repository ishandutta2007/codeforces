#include <iostream>
#include <math.h>
#include <iomanip>

typedef long double ldouble;

const ldouble PI = 3.141592653589793238L;

using namespace std;

ldouble radius (int sidec, ldouble sidel) {
  return sidel * (1 / sin(PI / sidec)) / 2;
}

ldouble apothem (int sidec, ldouble sidel) {
  return sidel * (1 / tan(PI / sidec)) / 2;
}

ldouble len [6];
ldouble vol [6];

int main () {
  cin >> len[3] >> len[4] >> len[5];

  /* Compute base area */
  for (int i = 3; i <= 5; i++) {
    vol[i] = apothem(i, len[i]) * i * len[i] / 2;
    vol[i] *= sqrt(len[i] * len[i] - radius(i, len[i]) * radius(i, len[i]));
    vol[i] /= 3.0L;
  }

  cout << fixed << setprecision(12) << vol[3] + vol[4] + vol[5] << endl;
}