/*
Author: AwakeAnay
Date: 12/02/2020
Time: 00:32:46
*/

#include <iostream>
#include <map>

#define int long long
#define MAX 67108865
std::map<int, int> bit;

signed main() {
  int n;
  std::cin >> n;
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;

    int b = 0;
    for(int j = 0; j < s.length(); j++) {
      int k = s[j]-'a';
      b ^= (1 << k);
    }
    
    ans += bit[b];

    for(int k = 0; k < 26; k++) {
      int d = b;
      d ^= (1 << k);
      ans += bit[d];
    }

    bit[b]++;
  }

  std::cout << ans;

  return 0;
}