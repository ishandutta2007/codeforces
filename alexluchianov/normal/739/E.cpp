#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const nmax = 2000;
pair<ld,int> dp[1 + nmax][1 + nmax];
ld v1[1 + nmax], v2[1 + nmax];

void computedp(int n, int k, ld target){
  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= k; j++)
      dp[i][j] = {0, 0};

  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= k; j++){

      dp[i][j] = dp[i - 1][j];
      if(dp[i][j].first < dp[i - 1][j].first + v2[i] - target)
        dp[i][j] = {dp[i - 1][j].first + v2[i] - target, dp[i - 1][j].second + 1};

      if(1 <= j){
        if(dp[i][j].first < dp[i - 1][j - 1].first + v1[i])
          dp[i][j] = {dp[i - 1][j - 1].first + v1[i], dp[i - 1][j - 1].second};

        ld cost = (1 - v1[i]) * v2[i];
        if(dp[i][j].first < dp[i - 1][j - 1].first + v1[i] + cost - target)
          dp[i][j] = {dp[i - 1][j - 1].first + v1[i] + cost - target, dp[i - 1][j - 1].second + 1};
      }
    }
}

int main()
{
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  for(int i = 1;i <= n; i++)
    cin >> v1[i];
  for(int i = 1;i <= n;i++)
    cin >> v2[i];
  ld from = 0, to = 1;
  for(ld step = 0; step < 30; step++){
    ld mid = (to + from) / 2;
    computedp(n, k1, mid);
    if(dp[n][k1].second < k2)
      to = mid;
    else
      from = mid;
  }
  computedp(n, k1, from);
  cout << setprecision(6) << fixed << dp[n][k1].first + dp[n][k1].second * from + (k2 - dp[n][k1].second) * from;

  return 0;
}