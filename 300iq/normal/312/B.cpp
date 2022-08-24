#include <bits/stdc++.h>

using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double p = a / b;
  double q = (1 - c / d) * (1 - p);
  cout << p / (1 - q) << endl;
}