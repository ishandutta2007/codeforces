#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int const nmax = 5000;
int const modulo = 1000000007;
int dp[1 + nmax], dp2[1 + nmax];

void processround(int n, int ban){
  for(int i = 1;i <= n; i++)
    dp2[i] = 0;

  for(int i = 1;i <= n; i++) {
    if(i == ban)
      continue;
    int dist = fabs(i - ban);
    int start = max(1, i - dist + 1), stop = min(n, i + dist - 1);

    dp2[start] += dp[i];
    if(modulo <= dp2[start])
      dp2[start] -= modulo;

    dp2[i] -= dp[i];
    if(dp2[i] < 0)
      dp2[i] += modulo;

    dp2[i + 1] += dp[i];
    if(modulo <= dp2[i])
      dp2[i] -= modulo;

    dp2[stop + 1] -= dp[i];
    if(dp2[stop + 1] < 0)
      dp2[stop + 1] += modulo;
  }

  for(int i = 1;i <= n; i++) {
    dp2[i] += dp2[i - 1];
    if(modulo <= dp2[i])
      dp2[i] -= modulo;
    dp[i] = dp2[i];
  }
}

int main()
{
  int n, k, a , b;
  cin >> n >> a >> b >> k;
  dp[a] = 1;
  for(int i = 1;i <= k; i++)
    processround(n, b);
  int result = 0;
  for(int i = 1;i <= n; i++){
    result += dp[i];
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}