#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const lgmax = 20;

std::set<int> myset[1 + lgmax];

int v[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  int smin = 0;

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    smin = std::min(smin, v[i]);
  }

  for(int i = 0;i <= n; i++)
    v[i] -= smin;
  
  for(int h = 0; h < lgmax; h++)
    for(int i = 0;i <= n; i++)
      myset[h].insert((v[i] & ((1 << (h + 1)) - 1)));

  std::vector<int> finalset;
  for(int i = 0; i < 25; i++)
    finalset.push_back(i);
  
  for(int mask = 0; mask <= nmax * 2; mask++) {
    std::vector<int> solset;
    for(int h = 0; h < lgmax; h++) {
      int mask2 = ((1 << (h + 1)) - 1) & mask;
      std::set<int>::iterator it = myset[h].lower_bound((1 << h) - mask2);

      if(it != myset[h].end() && (((*it) + mask2) & (1 << h))) {
        if(((1 << h) & (mask - smin)))
          solset.push_back(-(1 << h));
        else
          solset.push_back((1 << h));
      }
    }
    if(solset.size() < finalset.size()) {
      finalset = solset;
    }
  }
  
  std::cout << finalset.size() << '\n';
  for(int i = 0; i < finalset.size(); i++)
    std::cout << finalset[i] << " ";

  return 0;
}