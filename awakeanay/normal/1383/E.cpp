#include <iostream>
#include <vector>

#define int long long

const int MOD = 1000000007;

signed main() {
  std::string s;
  std::cin >> s;

  int n = s.length();

  int cur = 0;
  std::vector<int> blocks;
  for(int i = 0; i <= n; i++) {
    if(i == n || s[i] == '1') {
      blocks.push_back(cur);
      cur = 0;
    }
    cur += s[i] == '0';
  }

  int m = blocks.size();

  if(m == 1) {
    std::cout << n << std::endl;
    return 0;
  }

  int mult = ((blocks.front()+1)*(blocks.back()+1))%MOD;
  blocks.pop_back();
  blocks.push_back(0);

  int dp[m+1];
  int extra[m+1];
  int firstg[m+1];

  dp[m] = extra[m] = 0;
  dp[m-1] = 1; extra[m-1] = 0;
  firstg[m-1] = -1;

  for(int i = m-2; i >= 0; i--) {
    firstg[i] = i+1;
    while(firstg[i] != -1 && blocks[firstg[i]] <= blocks[i])
      firstg[i] = firstg[firstg[i]];
  }

  for(int i = m-2; i >= 1; i--) {
    dp[i] = 1 + (blocks[i]+1)*dp[i+1];
    dp[i] %= MOD;

    int j = firstg[i];
    extra[i] = 0;
    if(j != -1) {
      extra[i] = (blocks[j]-blocks[i])*dp[j+1] + extra[j];
      extra[i] %= MOD;
    }

    dp[i] = (dp[i] + extra[i])%MOD;
  }

  std::cout << (mult*dp[1])%MOD << std::endl;

  return 0;
}