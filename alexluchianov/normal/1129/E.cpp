#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 500;

int ask(std::vector<int> x, std::vector<int> y, int z) {
  if(x.size() == 0 || y.size() == 0)
    return 0;
  std::cout << x.size() << '\n';
  for(int i = 0; i < x.size(); i++) 
    std::cout << x[i] << " ";
  std::cout << '\n';
  std::cout << y.size() << '\n';
  for(int i = 0; i < y.size(); i++) 
    std::cout << y[i] << " ";
  std::cout << '\n';
  std::cout << z << std::endl;
  int val;
  std::cin >> val;
  return val;
}
int sz[1 + nmax];

std::vector<int> getPrefix(std::vector<int> aux, int val) {
  assert(val <= aux.size());
  std::vector<int> result;
  for(int i = 0; i < val; i++)
    result.push_back(aux[i]);
  return result;
}

int main() {
  int n;
  std::cin >> n;
  sz[1] = n - 1;
  for(int i = 2;i <= n; i++) {
    std::vector<int> aux;
    for(int j = 1; j <= n; j++)
      if(j != i && j != 1)
        aux.push_back(j);
    sz[i] = ask(aux, {1}, i);
  }
  std::vector<std::pair<int,int>> events;
  for(int i = 1;i <= n; i++) {
    events.push_back({sz[i], i});
  }
  std::sort(events.begin(), events.end());
  
  std::vector<int> leafs;
  std::vector<std::pair<int,int>> edges;

  for(int i = 0; i < events.size(); i++) {
    int node = events[i].second;
    while(0 < ask(leafs, {1}, node)) {
      int x = 0;
      for(int jump = (1 << 20); 0 < jump; jump /= 2) 
        if(x + jump <= leafs.size() && ask(getPrefix(leafs, x + jump), {1}, node) == 0)
          x += jump;
      edges.push_back({node, leafs[x]});
      leafs.erase(leafs.begin() + x);
    }
    leafs.push_back(node);
  }

  std::cout << "ANSWER\n";
  for(int i = 0; i < edges.size(); i++)
    std::cout << edges[i].first << " " << edges[i].second << '\n';
  std::cout << std::endl;
  return 0;
}