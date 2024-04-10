#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int n;
  std::cin >> n;
  if(n % 2 == 1)
    std::cout << "Ehab";
  else
    std::cout << "Mahmoud";
  return 0;
}