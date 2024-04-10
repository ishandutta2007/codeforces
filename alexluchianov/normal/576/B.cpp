#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int v[1 + nmax], seen[1 + nmax];

std::vector<int> getCycle(int node) {
  int start = node;
  std::vector<int> sol;
  do {
    sol.push_back(node);
    seen[node] = 1;
    node = v[node];
  } while(start != node);
  return sol;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  std::vector<std::vector<int>> sol;
  int smin = -1;
  bool allEven = true;
  for(int i = 1;i <= n; i++) {
    if(seen[i] == 0) {
      sol.push_back(getCycle(i));
      if(smin == -1 || sol.back().size() < sol[smin].size())
        smin = sol.size() - 1;
      if(sol.back().size() % 2 == 1)
        allEven = false;
    }
  }
  if(sol[smin].size() == 1) {
    std::cout << "YES\n";
    int root = sol[smin][0];
    for(int i = 1; i <= n; i++)
      if(i != root)
        std::cout << i << " " << root << '\n';
    std::cout << '\n';
  } else if(sol[smin].size() == 2 && allEven == true) {
    std::cout << "YES\n";
    int root = sol[smin][0], root2 = sol[smin][1];
    std::cout << root << " " << root2 << '\n';
    for(int i = 0; i < sol.size(); i++) {
      if(i != smin)
        for(int j = 0; j < sol[i].size(); j++) {
          if(j % 2 == 0)
            std::cout << root << " " << sol[i][j] << '\n';
          else
            std::cout << root2 << " " << sol[i][j] << '\n';
        }
    }
  } else
    std::cout << "NO\n";

  return 0;
}