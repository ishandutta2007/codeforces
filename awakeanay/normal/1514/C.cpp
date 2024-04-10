#include <iostream>
#include <vector>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> ans;
  ans.push_back(1);

  int inprod = 1;
  for(int i = 2; i < n; i++) {
    if(gcd(i, n) == 1) {
      inprod *= i;
      inprod %= n;
    }
  }

  if(inprod == 1)
    inprod = -1;

  for(int i = 2; i < n; i++) {
    if(gcd(i, n) == 1 && i != inprod)
      ans.push_back(i);
  }

  std::cout << ans.size() << std::endl;
  for(int j : ans)
    std::cout << j << " ";
  std::cout << std::endl;

  return 0;
}