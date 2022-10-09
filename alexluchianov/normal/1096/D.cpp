#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll const inf = 1000000000000000000;

char s[5 + nmax];
int cost[5 + nmax];
ll dp[5 + nmax][5];

int main()
{
  string word = "hard";

  int n;
  cin >> n;

  for(int i = 1 ; i <= n; i++) {
    cin >> s[i];
    dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4] = inf;
  }

  for(int i = 1 ; i <= n ; i++)
    cin >> cost[i];
  for(int i = 1 ; i <= n ; i++) {

    for(int j = 0 ; j <= 4 ; j++) {
      if(word[j] == s[i]){
        if(0 < j)
          dp[i][j] = MIN(dp[i - 1][j - 1] , dp[i - 1][j] + cost[i]);
        else
          dp[i][j] = dp[i - 1][j] + cost[i];

      } else
        dp[i][j] = dp[i - 1][j];
    }
  }

  cout << MIN(MIN(dp[n][0] , dp[n][1]) , MIN(dp[n][2] , dp[n][3]));

  return 0;
}