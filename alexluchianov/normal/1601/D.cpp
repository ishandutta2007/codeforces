#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, d;
  std::cin >> n >> d;
  
  std::vector<std::pair<int,int>> goodsport, badsport;

  for(int i = 1;i <= n; i++) {
    std::pair<int,int> val;
    std::cin >> val.first >> val.second;
    if(d <= val.first) {
      if(val.first < val.second)
        badsport.push_back({val.second, val.first});
      else
        goodsport.push_back(val);
    }
  }
  std::sort(goodsport.begin(), goodsport.end());
  std::sort(badsport.begin(), badsport.end());

  int ptr = 0;
  int result = goodsport.size();
  
  for(int i = 0; i < badsport.size(); i++) {
    while(ptr < goodsport.size() && goodsport[ptr].first < badsport[i].first) {
      d = std::max(d, goodsport[ptr].second);
      ptr++;
    }
    if(d <= badsport[i].second) {
      result++;
      d = std::max(d, badsport[i].first);
    }
  }
  std::cout << result << '\n';
  return 0;
}