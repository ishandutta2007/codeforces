#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 50000;
int const sigma = 5;
int v[1 + nmax][1 + sigma];

bool compare(int x, int y) {
  int acc = 0;
  for(int j = 1; j <= sigma; j++)
    acc += (v[y][j] < v[x][j]);
  return 3 <= acc;
}

int solve() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) 
    for(int j = 1;j <= sigma; j++)
      std::cin >> v[i][j];
  int smax = 1;
  for(int i = 2; i <= n; i++)
    if(compare(smax, i) == 1)
      smax = i;
  for(int i = 1;i <= n; i++)
    if(smax != i && compare(i, smax) == 0)
      return -1;
  return smax;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}