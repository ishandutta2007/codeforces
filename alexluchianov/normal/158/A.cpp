#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
int v[1 + nmax];

int main(){
  int n, k;
  std::cin >> n >> k;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  std::sort(v + 1, v + n + 1);
  std::reverse(v + 1, v + n + 1);
  int result = 0;
  for(int i = 1; i <= n; i++)
    if(v[k] <= v[i] && 0 < v[i])
      result++;
  std::cout << result;
}