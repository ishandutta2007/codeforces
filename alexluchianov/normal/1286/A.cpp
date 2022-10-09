#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int dp[1 + nmax][1 + nmax][2];
int v[1 + nmax], freq[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 0;i <= n; i++)
    for(int j = 0;j <= n; j++)
      for(int h = 0; h < 2; h++)
        dp[i][j][h] = nmax;
  dp[0][0][0] = dp[0][0][1] = 0;

  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    freq[v[i]]++;
  }
  int odd = 0;
  for(int i = 1;i <= n; i++)
    if(i % 2 == 1 && freq[i] == 0)
      odd++;

  for(int i = 1;i <= n; i++){
    if(0 < v[i]){
      if(v[i] % 2 == 1)
        for(int j = 0;j <= odd; j++)
          dp[i][j][1] = MIN(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
      else
        for(int j = 0; j <= odd; j++)
          dp[i][j][0] = MIN(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
    } else {
      for(int j = 1;j <= odd; j++)
        dp[i][j][1] = MIN(dp[i - 1][j - 1][0] + 1, dp[i - 1][j - 1][1]);
      for(int j = 0; j <= odd; j++)
        dp[i][j][0] = MIN(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
    }
  }
  cout << MIN(dp[n][odd][0], dp[n][odd][1]);
  return 0;
}