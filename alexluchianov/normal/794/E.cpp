#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int sol[1 + nmax];


int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(1 + n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    sol[n - 1] = std::max(sol[n - 1], v[i]);
  for(int i = 2;i < n; i++) {
    int sz = std::min(i - 2, n - i - 1);
    int val;
    if(v[i - 1] < v[i] && v[i + 1] < v[i])
      val = std::max(v[i - 1], v[i + 1]);
     else
      val = v[i];
    sol[n - 3 - sz * 2] = std::max(sol[n - 3 - sz * 2], val);
  }
  for(int i = 1;i < n; i++)
    sol[n - 2] = std::max(sol[n - 2], std::max(v[i], v[i + 1]));
  for(int i = 2; i < n - 1; i++) {
    int sz = std::min(i - 2, n - 2 - i);
    int val = std::max(v[i], v[i + 1]);
    sol[n - 4 - sz * 2] = std::max(sol[n - 4 - sz * 2], val);
  }
  for(int i = 2; i < n; i++)
    sol[i] = std::max(sol[i], sol[i - 2]);
  for(int i = 0; i < n; i++)
    std::cout << sol[i] << " ";
  return 0;
}