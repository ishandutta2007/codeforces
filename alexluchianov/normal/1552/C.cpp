#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100;
int seen[1 + 2 * nmax];

bool intersect(std::pair<int,int> f1, std::pair<int,int> f2) {
  int l = std::min(f1.second, f2.second) - std::max(f1.first, f2.first);
  l = std::max(l, 0);
  if(f1.second - f1.first == l)
    return false;
  if(f2.second - f2.first == l)
    return false;
  return 0 < l;
}

int solve() {
  int n, k;
  std::cin >> n >> k;
  for(int i = 1; i <= 2 * n; i++)
    seen[i] = 0;

  std::vector<std::pair<int,int>> sol;

  for(int i = 1; i <= k; i++) {
    int x, y;
    std::cin >> x >> y;
    seen[x] = seen[y] = 1;
    if(y < x)
      std::swap(x, y);
    sol.push_back({x, y});
  }
  std::vector<int> aux;
  for(int i = 1; i <= 2 * n; i++)
    if(seen[i] == 0)
      aux.push_back(i);
  int half = aux.size() / 2;
  for(int i = 0; i < half; i++)
    sol.push_back({aux[i], aux[i + half]});
  int result = 0;
  for(int i = 0; i < sol.size(); i++) 
    for(int j = i + 1; j < sol.size(); j++)
      result += intersect(sol[i], sol[j]);
  return result;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}