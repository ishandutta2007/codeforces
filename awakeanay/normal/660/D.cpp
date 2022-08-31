/*
Author: AwakeAnay
Date: 13/02/2020
Time: 16:15:22
*/

#include <iostream>
#include <map>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::pair<int, int> seq[n];
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i].first >> seq[i].second;
  }

  std::map<std::pair<int, int>, int> m;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      std::pair<int, int> mid = {seq[i].first + seq[j].first, seq[i].second + seq[j].second};
      ans += m[mid];
      m[mid]++;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}