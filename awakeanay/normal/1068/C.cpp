/*
Author: AwakeAnay
Date: 11/02/2020
Time: 23:46:09
*/

#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int> > inst[n];
  for(int i = 0; i < n; i++) {
    inst[i].push_back({i+1, i+1});
  }

  for(int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;
    inst[a].push_back({i+n+1, a+1});
    inst[b].push_back({i+n+1, b+1});
  }

  for(int i = 0; i < n; i++) {
    std::cout << inst[i].size() << std::endl;
    for(std::pair<int, int> j : inst[i])
      std::cout << j.first << " " << j.second << std::endl;
  }

  return 0;
}