#include <iostream>

using namespace std;

int main () {
  int d1, d2, d3;
  cin >> d1 >> d2 >> d3;
  cout << min(min(d1+d2+d3, d1*2+d2*2), min(d1*2+d3*2, d2*2+d3*2)) << endl;
}