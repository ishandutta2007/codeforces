/*
Author: AwakeAnay
Date: 17/02/2020
Time: 21:25:09
*/

#include <iostream>
#include <vector>

#define int long long 

signed main() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  std::vector<int> count(26, 0);
  std::vector<std::vector<int> > count2(26, std::vector<int>(26, 0));

  int max = 0;
  for(int i = 0; i < n; i++) {
    int cur = s[i]-'a';
    for(int j = 0; j < 26; j++) {
      count2[j][cur] += count[j];
      max = std::max(max, count2[j][cur]);
    }
    count[cur]++;
    max = std::max(max, count[cur]);
  }

  std::cout << max << std::endl;
  return 0;
}