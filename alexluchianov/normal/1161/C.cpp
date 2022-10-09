#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(1 + n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::sort(v.begin() + 1, v.end());
  if(v[n / 2 + 1] == v[1])
    std::cout << "Bob";
  else
    std::cout << "Alice";
  return 0;
}