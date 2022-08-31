#include <iostream>
#include <vector>
#include <complex>
#include <string>

using namespace std;

bool operator> (complex<long double> a, complex<long double> b) {
  if (imag(a) == 0 && imag(b) == 0) {
    return real(a) > real(b);
  } else if (imag(a) == 0 && imag(b) != 0) {
    return true;
  } else if (imag(a) != 0 && imag(b) == 0) {
    return false;
  } else if (imag(a) != 0 && imag(b) != 0) {
    return real(a) < real(b);
  }
}

complex<long double> eval (string expr, vector<complex<long double> > xyz) {
  if (expr.at(0) == '(') { /* (x^y)^z */
    complex<long double> x = xyz[(int) expr.at(1) - 'x'],
      y = xyz[(int) expr.at(3) - 'x'],
      z = xyz[(int) expr.at(6) - 'x'];
    return log(log(x)) + log(y * z);
  } else {
    complex<long double> x = xyz[(int) expr.at(0) - 'x'],
      y = xyz[(int) expr.at(2) - 'x'],
      z = xyz[(int) expr.at(4) - 'x'];
    return log(log(x)) + log(y) * z;
  }
}

int main () {
  long double ax, ay, az;
  cin >> ax >> ay >> az;
  
  vector<complex<long double> > xyz = {complex<long double> (ax, 0),
				       complex<long double> (ay, 0),
				       complex<long double> (az, 0)};

  complex<long double> cmax (3, 3);
  string exprs [9] = {"x^y^z", "x^z^y", "(x^y)^z",
		      "y^x^z", "y^z^x", "(y^x)^z",
		      "z^x^y", "z^y^x", "(z^x)^y"};

  string ans = "";
  for (int i = 0; i < 9; i++) {
    if (eval(exprs[i], xyz) > cmax) {
      cmax = eval(exprs[i], xyz);
      ans = exprs[i];
    }
  }

  cout << ans << endl;
}