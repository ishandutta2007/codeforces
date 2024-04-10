#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
 
using ll = long long;
 
int const nmax = 100000;
int far[5 + nmax];

void print(int node) {
  std::cout << node << " ";
  if(far[node] != node)
    print(far[node]);
}

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  s = "#" + s;
  std::vector<std::pair<int, int>> per[2][2];
  for(int i = 1;i <= n; i++)
    far[i] = i;
  for(int i = 1;i <= n; i++) {
    int bit = (s[i] == 'R');
    bool found = false;
    for(int j = 0; j < 2; j++)
      if(0 < per[j][!bit].size() && 0 < per[j][bit].size()) {
        per[j][bit].push_back(per[j][!bit].back());
        per[j][!bit].pop_back();
        far[per[j][bit].back().second] = i;
        per[j][bit].back().second = i;
        found = true;
        break;
      }
    if(found == true)
      continue;
    for(int fj = 0; fj < 2; fj++) {
      int j = fj ^ bit;
      if(0 < per[j][!bit].size()) {
        per[j][bit].push_back(per[j][!bit].back());
        per[j][!bit].pop_back();
        far[per[j][bit].back().second] = i;
        per[j][bit].back().second = i;
        found = true;
        break;
      }
    }
    if(found == true)
      continue;
    per[bit][bit].push_back({i, i});
  }
  
  std::cout << per[0][0].size() + per[0][1].size() + per[1][0].size() + per[1][1].size() - 1 << '\n';
  int last = 0;
  if(per[1][1].size() < per[0][0].size())
    last = 1;
  else if(per[0][0].size() < per[1][1].size())
    last = 0;
  else {
    last = (0 == (per[1][0].size()) && 0 == per[1][1].size());
  }
  while(0 < per[0][0].size() || 0 < per[0][1].size() || 
        0 < per[1][0].size() || 0 < per[1][1].size()) {
    
    if(0 < per[!last][last].size()) {
      assert(0 < per[!last][last].size());
      print(per[!last][last].back().first);
      per[!last][last].pop_back();
    } else {
      print(per[!last][!last].back().first);
      per[!last][!last].pop_back();
      last = !last;
    }
  }

  std::cout << '\n';
  return 0;
}