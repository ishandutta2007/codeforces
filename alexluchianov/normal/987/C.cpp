#include <iostream>

using namespace std;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 3000;
int const inf = 1000000000;

int v[5 + nmax];
int cost[5 + nmax];
int dp[3][5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i];
  for(int i = 1 ; i <= n ;i++)
    cin >> cost[i];
  int smin = inf;
  for(int i = 1 ; i <= n ;i++){
    dp[0][i] = cost[i];
    dp[1][i] = dp[2][i] = inf;
    for(int j = 1 ; j < i ; j++)
      if(v[j] < v[i]){
        dp[1][i] = MIN(dp[1][i] , dp[0][j] + cost[i]);
        dp[2][i] = MIN(dp[2][i] , dp[1][j] + cost[i]);
      }
    smin = MIN(smin , dp[2][i]);
  }
  if(smin == inf)
    cout << -1;
  else
    cout << smin;
  return 0;
}