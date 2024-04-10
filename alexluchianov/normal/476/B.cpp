#include <iostream>
#include <iomanip>

using namespace std;

using ld = long double;
int const nmax = 15;
ld dp[1 + 2 * nmax][1 + 2 * nmax];

int main()
{
  string s, s2;
  cin >> s >> s2;
  dp[0][nmax] = 1;
  for(int i = 0; i < s2.size(); i++){
    if(s2[i] == '+')
      for(int j = 1;j < 2 * nmax; j++)
        dp[i + 1][j] = dp[i][j - 1];
    else if(s2[i] == '-')
      for(int j = 1;j < 2 * nmax; j++)
        dp[i + 1][j] = dp[i][j + 1];
    else
      for(int j = 1;j < 2 * nmax; j++)
        dp[i + 1][j] = (dp[i][j - 1] + dp[i][j + 1]) / 2.0;
  }
  int val = 0;
  for(int i = 0; i < s.size(); i++)
    if(s[i] == '+')
      val++;
    else
      val--;
  cout << setprecision(10) << fixed << dp[s2.size()][nmax + val];
  return 0;
}