#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int dist(int x, int y, int x2, int y2) {
  return fabs(x - x2) + fabs(y - y2);
}

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int,int>> v(n);
  for(int i = 0;i < n; i++) 
    std::cin >> v[i].first >> v[i].second;
  for(int i = 0; i < n; i++) {
    bool valid = 1;
    for(int j = 0; j < n; j++)
      if(i != j && k < dist(v[i].first, v[i].second, v[j].first, v[j].second))
        valid = 0;
    if(valid == 1)
      return 1;
  }
  return -1;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
}