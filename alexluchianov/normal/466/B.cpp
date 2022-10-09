#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
ll const inf = 1000000000000000000;

int main() {
  ll n, a, b;
  std::cin >> n >> a >> b;
  if(6 * n <= a * b) {
    std::cout << a * b << " " << a << " " << b << '\n';
    return 0;
  }
  ll result = inf;
  ll sola = 0, solb = 0;
  for(int i = 1; 1LL * (i - 1) * (i - 1) <= 6 * n; i++) {
    ll oth = (6 * n + i - 1) / i;
    ll newa = std::max(a, 1LL * i), newb = std::max(b, 1LL * oth);
    if(1LL * newa * newb < result) {
      result = 1LL * newa * newb;
      sola = newa;
      solb = newb;
    }
    newa = std::max(a, 1LL * oth);
    newb = std::max(b, 1LL * i);
    if(1LL * newa * newb < result) {
      result = 1LL * newa * newb;
      sola = newa;
      solb = newb;
    }
  }
  std::cout << result << '\n' << sola << " " << solb << '\n';
  return 0;
}