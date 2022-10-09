#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const lgmax = 20;
int dp[(1 << lgmax)], dp2[(1 << lgmax)];
std::vector<int> real;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::string s;
  int k;
  std::cin >> s >> k;
  int destroymask = 0;
  for(int i = 1;i < k; i++)
    if(k % i == 0)
      destroymask |= (1 << i);

  for(int mask = 1; mask < (1 << k); mask += 2)
    if(0 == (mask & (mask<<1)) )
      real.push_back(mask);
  
  
  for(int i = 0;i < s.size(); i++) {
    int val = s[i] - '0';
    for(int j = 0; j < real.size(); j++) {
      ll mask = real[j];
      ll newmask = (mask<<val) | (1 << 0);
      
      if((0 == (newmask & destroymask)) && 0 < (newmask & (1 << k)))
        continue;
      else {
      
        newmask = (newmask & ((1 << k) - 1));
        if(0 < (newmask & destroymask)) {
          int newmask2 = 0;
          for(int h = 0; h < k; h++)
            if((1 << h) & newmask & destroymask)
              break;
            else
              newmask2 |= ((1 << h) & newmask);
          newmask = newmask2;
        }
        dp2[newmask] = std::max(dp2[newmask], dp[mask] + 1);
      }
    }
    for(int j = 0; j < real.size(); j++)
      dp[real[j]] = dp2[real[j]];
  }

  int result = 0;
  for(int i = 0; i < (1 << k); i++)
    result = std::max(result, dp[i]);
  std::cout << s.size() - result;
  return 0;
}