#include <iostream>
#include <math.h>
#include <iomanip>

typedef long double ldouble;

using namespace std;

int main () {
  ldouble a, b, c;
  cin >> a >> b >> c;

  ldouble discrim = sqrt(b * b - 4 * a * c);
  ldouble roota = (-b + discrim) / (2.0L * a);
  ldouble rootb = (-b - discrim) / (2.0L * a);
  cout << fixed << setprecision(12) << max(roota, rootb) << endl;
  cout << fixed << setprecision(12) << min(roota, rootb) << endl;
}