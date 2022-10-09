#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int v[1 + nmax], seen[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> sol;
  for(int i = 1; i <= n; i++) 
    std::cin >> v[i];
  for(int i = 1; i <= n; i++) {
    int id = 0;
    for(int j = 1; j <= n; j++)
      if(seen[j] == 0 && (v[j] < v[id] || id == 0))
        id = j;
    seen[id] = 1;
    for(int j = id; 1 <= j; j--) 
      if(seen[j] == 0)
        sol.push_back({j, id});
  }
  std::reverse(sol.begin(), sol.end());
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
}