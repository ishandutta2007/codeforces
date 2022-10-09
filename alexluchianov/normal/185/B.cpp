#include <iostream>
#include <vector>
#include <iomanip>

using ll = long long;
using ld = long double;

ld const eps = 0.0000000001;
ld sum, a, b, c;

bool test(ld target) {
  return (a / target + b / target + c / target) <= sum;
}


int main() {
  std::cin >> sum >> a >> b >> c;
  ld from = 100000000;
  ld to = eps;
  for(int steps = 1; steps <= 1000; steps++) {
    ld mid = (from + to) / 2;
    if(test(mid) == 1) {
      from = mid;
    } else
      to = mid;
  }
  std::cout << std::setprecision(14) << std::fixed << a / from << " " << b / from << " " << c / from << '\n';

  return 0;
}