#include <iostream>
#include <cmath>
#include <iomanip>

typedef long double ldouble;

const ldouble EPS = 0.0000001;

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int cutc;
  ldouble h;
  cin >> cutc >> h;

  ldouble area = h / (2 * cutc);
  cout << fixed << setprecision(12);
  for (int i = cutc - 1; i > 0; i--) {
    cout << sqrt(2 * (cutc - i) * area * h) << " ";
  }

  cout << endl;
}