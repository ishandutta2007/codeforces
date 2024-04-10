#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];

int main() {
  int n, lim;
  std::cin >> n >> lim;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  int ptr = 1;
  ld result = -1;

  for(int i = 1;i <= n; i++) {
    ptr = std::max(ptr, i);
    while(ptr < n && v[ptr + 1] - v[i] <= lim)
      ptr++;
    if(i + 1 < ptr && ptr <= n) 
      result = std::max(result, ld((v[ptr] - v[i + 1])) / (v[ptr] - v[i]));
  }
  if(result == -1)
    std::cout << result;
  else
    std::cout << std::setprecision(9) << std::fixed << result;
  return 0;
}