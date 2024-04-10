#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

ll normalpow(int number, int k) {
  ll result = number;
  for(int i = 2; i <= k; i++)
    result *= number;
  return result;
}

int main() {
  int n, l, r;
  std::cin >> n >> l >> r;
  if(n == 1)
    std::cout << r - l + 1 << '\n';
  else if(n == 2)
    std::cout << 1LL * (r - l + 1) * (r - l + 1) - (r - l + 1) << '\n';
  else if(n <= 31){
    ll result = 0;
    int k = n - 1;
    for(int p = 1; normalpow(p, k) <= r; p++)
      for(int q = 1; normalpow(q, k) <= r; q++)
        if(std::__gcd(p, q) == 1 && (p + q) != 2) {
          ll powp = normalpow(p, k);
          ll powq = normalpow(q, k);
          ll left = std::max(1LL * l, (l * powq + powp - 1) / powp);
          ll right = std::min(1LL * r, (r * powq) / powp);
          result += std::max(0LL, right / powq - (left - 1) / powq);
        }
    std::cout << result << '\n';
  } else
    std::cout << 0 << '\n';
  return 0;
}