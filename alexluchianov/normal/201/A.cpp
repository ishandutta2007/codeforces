#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int f(int n) {
  if(n % 2 == 0)
    return ((n / 2 - 1) / 2) * ((n / 2 - 1) / 2) * 4;
  else
    return n * n / 2 + 1;
}
int possible(int n, int k) {
  if(f(n) < k)
    return 0;
  if(n == 3) {
    if(k % 4 == 0 || k % 4 == 1)
      return 1;
    else if(k == 2)
      return 1;
    return 0;
  } else if(n % 2 == 0) {
    return (k % 4) == 0;
  } else
    return 1;
}
int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= 100; i++)
    if(possible(i, n) == 1) {
      std::cout << i;
      return 0;
    }
  return 0;
}