#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;

typedef long double ld;

int main () {
  int n, r;
  cin >> n >> r;

  ld alpha = 2 * (ld) M_PI / (ld) n;
  ld beta = (ld) (n - 2) * (ld) M_PI / (ld) (2 * n);

  ld R = - (r * sin(alpha)) / (sin(alpha) - 2 * sin(beta));
  cout << fixed << " " << setprecision(12) << R << endl;
}