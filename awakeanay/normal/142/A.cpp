#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> d;

  for(int i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      d.push_back(i);
      if(i*i != n)
        d.push_back(n/i);
    }
  }

  int min = (n+1)*3*3 - n;
  int max = min;

  for(int j : d) {
    int k = n/j;
    for(int l = 1; l*l <= k; l++) {
      if(k%l == 0) {
        min = std::min(min, (j+1)*(l+2)*((k/l) +2) - n);
      }
    }

  }

  std::cout << min << " " << max << std::endl;
  return 0;
}