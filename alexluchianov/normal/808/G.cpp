#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100000;
int pre[1 + nmax];

void computepre(string s){
  int x = 2, ptr = 0;
  while(x <= s.size()){
    if(s[ptr + 1] == s[x]){
      ptr++;
      pre[x] = ptr;
      x++;
    } else if(0 < ptr)
      ptr = pre[ptr];
    else {
      pre[x] = 0;
      x++;
    }
  }
}
vector<int> dp[1 + nmax];
int main()
{
  string s, pattern;
  cin >> s >> pattern;
  int n = s.size(), p = pattern.size();
  s = "#" + s;
  pattern = "#" + pattern;
  computepre(pattern);
  for(int i = 0; i <= n; i++){
    dp[i].resize(1 + p);
    for(int j = 0; j <= p; j++)
      dp[i][j] = -nmax;
  }
  dp[0][0] = 0;

  for(int i = 1;i <= n; i++){
    for(int j = 0; j <= p; j++)
      dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    for(int j = 1; j <= p; j++)
      if(s[i] == pattern[j] || s[i] == '?')
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
    dp[i][p]++;
    for(int j = p; 0 <= j; j--)
      dp[i][pre[j]] = max(dp[i][pre[j]], dp[i][j]);
  }
  int result = 0;
  for(int i = 0; i <= p; i++)
    result = max(result, dp[n][i]);
  cout << result;
  return 0;
}