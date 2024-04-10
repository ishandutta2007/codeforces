#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x, y;
  cin >> x >> y;
  double lx = log(x);
  double ly = log(y);
  if(abs(x * ly - y * lx) < 0.000001)
    cout << "=" << endl;
  else if(x * ly < y * lx)
    cout << ">" << endl;
  else
    cout << "<" << endl;
  return 0;
}