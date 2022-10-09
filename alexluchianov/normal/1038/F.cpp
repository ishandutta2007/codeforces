#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 40;
ll dp[1 + nmax][1 + nmax][1 + nmax];
bool compat[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  for(int i = 1; i < s.size(); i++) {
    compat[i] = true;
    for(int j = i; j < s.size(); j++)
      compat[i] &= (s[j] == s[j - i]);
  }
  ll result = 0;
  
  for(int i = 0; i < n; i++) {
    dp[i][i][i] = -1;
    if(0 < i) {
      for(int j = 0; j < i; j++)
        for(int j2 = j; j2 < i; j2++)
          dp[i][j][j2] += dp[i - 1][j][j2];
      for(int j = 0; j < i; j++)
        for(int j2 = j; j2 < i; j2++)
          if(s.size() <= i - j2 || compat[i - j2] == true)
            dp[i][j][i] -= (dp[i - 1][j][j2] * (1LL<<(std::max(0, int(i - j2 - (int)s.size())))));
    }
  }
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++) {
      int dist = i + n - j;
      if(s.size() <= dist || compat[dist] == true)
        result += dp[n - 1][i][j] * (1LL<<(std::max(int(i + n - j - (int)s.size()), 0)));
    }
  std::cout << -result << '\n';
  return 0;
}