/*
Author: AwakeAnay
Date: 13/02/2020
Time: 17:14:44
*/

#include <iostream>
#include <vector>

#define int long long
#define INF 20000000000000000000

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;

  int sum = 0;
  int seq[n];

  for(int i = 0; i < n; i++) {
    std::cin >> seq[i];
    sum += seq[i];
    if(i) seq[i] += seq[i-1];
  }

  if(sum == 1) {
    std::cout << -1 << std::endl;
    return 0;
  }

  int i;
  std::vector<int> div;
  for(i = 2; i*i <= sum; i++) {
    if(sum % i == 0) {
      div.push_back(i);
      while(sum%i == 0)
        sum /= i;
    }
  }
  if(sum != 1) div.push_back(sum);

  int ans = INF;
  for(int j : div) {
    int cur = 0;
    for(int i = 0; i < n; i++)
      cur += std::min(seq[i]%j, j-seq[i]%j);
    ans = std::min(ans, cur);
  }

  std::cout << ans << std::endl;

  return 0;
}