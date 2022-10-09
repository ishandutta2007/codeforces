#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int equal[1 + nmax];
int equal2[1 + nmax];

void ask(std::vector<int> aux) {
  if(0 == aux.size())
    return ;
  std::cout << "Q " << aux.size() / 2 << " ";
  for(int i = 0; i < aux.size(); i++)
    std::cout << aux[i] << " ";
  std::cout << std::endl;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> aux;
  for(int i = 1; i < n; i += 2) {
    aux.push_back(i);
    aux.push_back(i + 1);
  }
  ask(aux);
  aux.clear();
  
  for(int i = 1;i < n; i += 2) {
    char val;
    std::cin >> val;
    equal[i + 1] = val - '0';
  }

  for(int i = 2;i < n; i += 2)  {
    aux.push_back(i);
    aux.push_back(i + 1);
  }
  ask(aux);
  aux.clear();

  for(int i = 2;i < n; i += 2) {
    char val;
    std::cin >> val;
    equal[i + 1] = val - '0';
  }
  int last = 1;
  std::vector<std::pair<int,int>> sol;
  for(int i = 2; i <= n; i++)
    if(equal[i] == 0) {
      sol.push_back({last, i - 1});
      last = i;
    }
  sol.push_back({last, n});
  
  for(int i = 2; i < sol.size(); i += 4) {
    aux.push_back(sol[i - 2].first);
    aux.push_back(sol[i].first); 
  }
  ask(aux);
  aux.clear();
  for(int i = 2; i < sol.size(); i += 4) {
    char val;
    std::cin >> val;
    equal2[i] = val - '0';
  }
  for(int i = 3; i < sol.size(); i += 4) {
    aux.push_back(sol[i - 2].first);
    aux.push_back(sol[i].first); 
  }
  ask(aux);
  aux.clear();
  for(int i = 3; i < sol.size(); i += 4) {
    char val;
    std::cin >> val;
    equal2[i] = val - '0';
  }
  for(int i = 4; i < sol.size(); i += 4) {
    aux.push_back(sol[i - 2].first);
    aux.push_back(sol[i].first); 
  }
  ask(aux);
  aux.clear();
  for(int i = 4; i < sol.size(); i += 4) {
    char val;
    std::cin >> val;
    equal2[i] = val - '0';
  }
  for(int i = 5; i < sol.size(); i += 4) {
    aux.push_back(sol[i - 2].first);
    aux.push_back(sol[i].first); 
  }
  ask(aux);
  aux.clear();
  for(int i = 5; i < sol.size(); i += 4) {
    char val;
    std::cin >> val;
    equal2[i] = val - '0';
  }
  std::vector<int> groups[3];
  int last2 = 1;
  last = 0;
  for(int i = 0; i < sol.size(); i++) {
    int color = 0;
    if(i == 0) {
      color = 0;
    } else if(i == 1)
      color = 1;
    else {
      if(equal2[i] == 1)
        color = last;
      else
        color = 3 - last - last2;
      last = last2;
      last2 = color;
    }

    for(int j = sol[i].first; j <= sol[i].second; j++)
      groups[color].push_back(j);
  }

  std::cout << "A " << groups[0].size() << " " << groups[1].size() << " " << groups[2].size() << std::endl;

  for(int h = 0; h < 3; h++) {
    for(int i = 0; i < groups[h].size(); i++)
      std::cout << groups[h][i] << " ";
    std::cout << '\n';
  }
  std::cout << std::endl;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}