#include <iostream>

using namespace std;

long long xdig [10], ydig [10];
long long xc, yc;
long long x, y;
long long xbase, ybase;

long long pow (long long base, long long exp) {
  long long ans = 1;
  for (int i = 0; i < exp; i++) {
    ans *= base;
  }
  return ans;
}

int main () {
  cin >> xc >> xbase;
  for (int i = 0; i < xc; i++) {
    cin >> xdig[i];
    x += xdig[i]*pow(xbase, xc-i-1);
  }

  cin >> yc >> ybase;
  for (int i = 0; i < yc; i++) {
    cin >> ydig[i];
    y += ydig[i]*pow(ybase, yc-i-1);
  }

  if (x < y) cout << "<" << endl;
  else if (x == y) cout << "=" << endl;
  else cout << ">" << endl;
  return 0;
}