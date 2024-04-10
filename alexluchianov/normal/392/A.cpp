#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  ll result = 0;
  int n;
  std::cin >> n;
  if(n == 0) {
    std::cout << 1;
    return 0;
  }
  int last = n;
  for(int i = 1;i <= n; i++) {
    int curr = last;
    while(1LL * n * n < 1LL * i * i + 1LL * curr * curr)
      curr--;
    result += 1 + std::max(last - curr - 1, 0);
    last = curr;
  } 
  std::cout << result * 4;
}