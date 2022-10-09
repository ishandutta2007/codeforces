#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 3000;
int v[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  std::vector<std::pair<int,int>> sol;

  for(int i = 0;i < n; i++) {
    int smin = i;
    for(int j = i + 1; j < n; j++)
      if(v[j] < v[smin])
        smin = j;
    if(i != smin) {
      sol.push_back({smin, i});
      std::swap(v[smin], v[i]);
    }
  }

  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  return 0;
}