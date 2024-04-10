#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, speed;
  std::cin >> n >> speed;
  std::vector<int> kickTime(n);
  for(int i = 0; i < n; i++) 
    std::cin >> kickTime[i];
  std::vector<std::pair<ll,ll>> aux;
  for(int i = 0; i < n; i++) {
    int pos;
    std::cin >> pos;
    if(pos - 1LL * kickTime[i] * speed <= 0 && 0 <= pos + 1LL * kickTime[i] * speed)
      aux.push_back({pos - 1LL * kickTime[i] * speed, pos + 1LL * kickTime[i] * speed});
    
  }
  std::sort(aux.begin(), aux.end(), [&](std::pair<ll, ll> f1, std::pair<ll, ll> f2){
    if(f1.first != f2.first)
      return f2.first < f1.first ;
    else
      return f1.second < f2.second;
  });

  std::set<std::pair<ll, int>> myset;
  
  for(int i = 0; i < aux.size(); i++) {
    ll pos = aux[i].second;
    std::set<std::pair<ll, int>>::iterator it = myset.upper_bound({pos, i});
    if(it != myset.end())
      myset.erase(it);
    myset.insert({pos, i});
  }
  std::cout << myset.size() << '\n';

  return 0;
}