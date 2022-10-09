#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using ll = long long;
using ld = long double;

int const nmax = 50000;
int const sigma = 30;
int v[5 + nmax], deg[5 + nmax];

std::vector<std::pair<std::pair<int, int>,int>> base;
int basemask[5 + nmax];

int reduce(int number, int &mask){
  for(int i = 0; i < base.size(); i++) 
    if(0 < (number & (1 << base[i].first.first))) {
      number ^= (base[i].first.second);
      mask ^= basemask[i];
    }
  return number;
}

ld lgpow(ld a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    ld result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, modulo;
  std::cin >> n >> modulo;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];

  for(int i = 1;i <= n; i++) {
    int val = v[i];
    deg[i] = 1;
    while(0 < val) {
      val /= 10;
      deg[i] *= 10;
    }
  }
  
  std::vector<int> others;
  for(int i = 1;i <= n; i++) {
    int mask = 0;
    int val = reduce(v[i], mask);
    if(0 < val){
      for(int j = 0; j < sigma; j++)
        if((1 << j) & val) {
          base.push_back({{j, val}, i});
          basemask[base.size() - 1] = mask ^ (1 << (base.size() - 1));
          break;
        }
    } else
      others.push_back(i);
  }

  int lim = std::min(22, (int)others.size());
  
  for(int mask = 0; mask < others.size(); mask++) {
    std::vector<int> chosen;
    int number = 0;
    chosen.push_back(others[mask]);
    number ^= v[others[mask]];
    
    int mask2 = 0;
    for(int i = 0; i < base.size(); i++)
      if((1 << base[i].first.first) & number) {
        number ^= base[i].first.second;
        mask2 ^= basemask[i];
      }

    for(int j = 0; j < base.size(); j++)
      if(0 < (mask2 & (1 << j)))
        chosen.push_back(base[j].second);

    
    std::sort(chosen.begin(), chosen.end());
    int result = 0;

    for(int i = 0; i < chosen.size(); i++)
      result = (1LL * result * deg[chosen[i]] + v[chosen[i]]) % modulo;
    
    if(0 < chosen.size() && 0 == result) {
      std::cout << "Yes\n";
      std::cout << chosen.size() << '\n';
      for(int i = 0; i < chosen.size(); i++)
        std::cout << chosen[i] << " ";
      std::cout << '\n';
      return 0;
    }
  }

  for(int mask = 0; mask < (1 << lim); mask++) {
    std::vector<int> chosen;
    int number = 0;
    for(int i = 0; i < lim; i++) 
      if(mask & (1 << i)) {
        chosen.push_back(others[i]);
        number ^= v[others[i]];
      }
    
    int mask2 = 0;
    for(int i = 0; i < base.size(); i++)
      if((1 << base[i].first.first) & number) {
        number ^= base[i].first.second;
        mask2 ^= basemask[i];
      }

    for(int j = 0; j < base.size(); j++)
      if(0 < (mask2 & (1 << j)))
        chosen.push_back(base[j].second);

    
    std::sort(chosen.begin(), chosen.end());
    int result = 0;

    for(int i = 0; i < chosen.size(); i++)
      result = (1LL * result * deg[chosen[i]] + v[chosen[i]]) % modulo;
    
    if(0 < chosen.size() && 0 == result) {
      std::cout << "Yes\n";
      std::cout << chosen.size() << '\n';
      for(int i = 0; i < chosen.size(); i++)
        std::cout << chosen[i] << " ";
      std::cout << '\n';
      return 0;
    }
  }

  std::cout << "No\n";
  return 0;
}