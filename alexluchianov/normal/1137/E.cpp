#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <queue>

using ll = long long;

int const nmax = 300000;
std::set<std::pair<int,ll>> myset;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  
  ll base = 0;
  ll evalpoint = 0;

  myset.insert({0, 0});
  
  std::priority_queue<std::pair<ll,int>, std::vector<std::pair<ll,int>>, std::greater<std::pair<ll,int>>> pq;
  for(int i = 1; i <= m; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int k;
      std::cin >> k;
      myset.clear();
      while(0 < pq.size())
        pq.pop();

      n += k;
      base = 0;
      evalpoint = 0;
      myset.insert({0, 0});
    } else if(op == 2) {
      int k;
      std::cin >> k;
      std::pair<int,ll> prev = *myset.rbegin();
      std::pair<int, ll> curr = {n, -base -  n * evalpoint};
      pq.push({(prev.second - curr.second + curr.first - prev.first - 1) / (curr.first - prev.first), curr.first});
      myset.insert(curr);
      n += k;
    } else {
      int b, s;
      std::cin >> b >> s;
      evalpoint += s;
      base += b;
    }

    while(0 < pq.size() && pq.top().first <= evalpoint) {
      int node = pq.top().second;
      
      pq.pop();
      std::set<std::pair<int,ll>>::iterator it = myset.lower_bound({node, 0});
      if(it == myset.end() || (it != myset.begin() && it->first != node))
        it--;
      if(it->first != node)
        continue;
      
      myset.erase(it++);
      if(it != myset.end() && it != myset.begin()) {
        std::pair<int, ll> curr = *it;
        it--;
        std::pair<int,ll> prev = *it;
        pq.push({(prev.second - curr.second + curr.first - prev.first - 1) / (curr.first - prev.first), curr.first});
      }
    }

    std::cout << myset.rbegin()->first + 1 << " " << myset.rbegin()->second + myset.rbegin()->first * evalpoint + base << '\n';
  }
  return 0;
}