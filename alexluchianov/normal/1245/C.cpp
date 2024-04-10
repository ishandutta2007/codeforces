#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;
int dp[6 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++)
    if(s[i] == 'w' || s[i] == 'm') {
      cout << 0;
      return 0;
    }

  s = "#" + s;
  dp[0] = 1;
  for(int i = 1;i < s.size(); i++){
    dp[i] = dp[i - 1];
    if(s[i] == 'u' && s[i - 1] == 'u')
      dp[i] += dp[i - 2];
    else if(s[i] == 'n' && s[i - 1] == 'n')
      dp[i] += dp[i - 2];
    if(modulo <= dp[i])
      dp[i] -= modulo;
  }
  cout << dp[s.size() - 1];
  return 0;
}
/*
1
2
1 1 0
RR
*/