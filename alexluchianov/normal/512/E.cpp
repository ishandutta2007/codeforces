#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;

int const nmax = 1000;
std::vector<std::pair<int,int>> sol;
  
std::vector<std::pair<int,int>> edges;

void solve(int from, int to, int op) {
  assert(from < to);

  if(from + 1 == to)
    return ;
  else {
    int mid = 0;
    for(int h = 0; h < edges.size(); h++) {
      std::pair<int,int> e = edges[h];
      if(e.first == 1 && from < e.second && e.second < to) {
        mid = e.second;
      } else if(from < e.first && e.first < to && e.second == 1)
        mid = e.first;
    }
    if(0 < mid) {
      solve(from, mid, op);
      solve(mid, to, op);
      return ;
    }
    bool done = false;
    for(int h = 0; h < edges.size(); h++) {
      std::pair<int,int> e = edges[h];
      if(e.first == from && e.second == to) {
        edges.erase(edges.begin() + h);
        done = true;
      } else if(e.first == to && e.second == from) {
        edges.erase(edges.begin() + h);
        done = true;
      }
    }
    assert(done == true);
    mid = from + 1;
    for(int h = 0; h < edges.size(); h++) {
      std::pair<int,int> e = edges[h];
      if(e.first == from) 
        mid = std::max(mid, e.second);
      else if(e.second == from) 
        mid = std::max(mid, e.first);
    }
    if(op == 0)
      sol.push_back({from, to});
    else
      sol.push_back({1, mid});
    edges.push_back({1, mid});
    solve(from, mid, op);
    solve(mid, to, op);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n - 3; i++) {
    int x, y;
    std::cin >> x >> y;
    edges.push_back({x, y});
  }
  solve(2, n, 0);
  edges.clear();
  std::vector<std::pair<int,int>> sol2 = sol;
  sol.clear();

  for(int i = 1;i <= n - 3; i++) {
    int x, y;
    std::cin >> x >> y;
    edges.push_back({x, y});
  }
  solve(2, n, 1);
  std::reverse(sol.begin(), sol.end());
  sol2.insert(sol2.end(), sol.begin(), sol.end());
  sol = sol2;
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  return 0;
}