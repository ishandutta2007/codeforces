#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int getsum(int x, int y) {
  std::cout << "or " << x << " " << y << std::endl;
  int a;
  std::cin >> a;
  std::cout << "and " << x << " " << y << std::endl;
  int b;
  std::cin >> b;
  return a + b;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int a = getsum(1, 2), b = getsum(2, 3), c = getsum(3, 1);
  ll sum = (1LL * a + b + c) / 2;
  std::vector<int> sol;
  sol.push_back(sum - a);
  sol.push_back(sum - b);
  sol.push_back(sum - c);
  for(int i = 4; i <= n; i++)
    sol.push_back(getsum(1, i) - (sum - b));
  std::sort(sol.begin(), sol.end());
  std::cout << "finish " << sol[k - 1] << std::endl;

  return 0;
}