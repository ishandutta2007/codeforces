#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const modulo = 998244353;
int orig[5 + nmax];

int solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> orig[i];

  std::vector<std::pair<int,std::pair<int,int>>> v;
  
  int result = 0;
  for(int i = n; 1 <= i; i--) {
    int k = 1;
    int ptr = v.size() - 1;
    std::vector<std::pair<int,std::pair<int,int>>> v2;
    while(k <= orig[i]) {
      int val = (orig[i] / k) + (0 < (orig[i] % k));
      std::pair<int,int> result = {(k == 1), 0};

      while(0 <= ptr && val <= v[ptr].first) {
        result.first += v[ptr].second.first;
        result.second += v[ptr].second.second;
        if(modulo <= result.first)
          result.first -= modulo;
        if(modulo <= result.second)
          result.second -= modulo;
        ptr--;
      }
      v2.push_back({orig[i] / k, {result.first, (result.second + 1LL * (k - 1) * result.first) % modulo} });
      
      int k2 = (orig[i] / (orig[i] / k));
      if(k2 == k)
        k++;
      else
        k = k2;
    }
    std::swap(v, v2);
    std::reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
      result += v[i].second.second;
      if(modulo <= result)
        result -= modulo;
    }
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}