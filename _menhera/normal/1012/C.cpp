#include<bits/stdc++.h>
using namespace std;
int N;
int a[5050];
int dig[5050];
int dp[5050][5050][2]; //i, cnt, pExcav?
int main()
{
  scanf("%d", &N);
  for(int i=1; i<=N; ++i) scanf("%d", a+i);
  memset(dp, 0x3f, sizeof dp);
  if(a[1] > a[2])
  {
    dp[1][0][0] = 0;
    dp[1][1][1] = 0;
  }
  else
  {
    dp[1][0][0] = 0;
    dp[1][1][1] = a[2]-a[1]+1;
  }
  for(int i=2; i<=N; ++i)
  {
    dp[i][0][0] = 0;
    for(int c=1; c<=i; ++c)
    {
      //we will pass at i
      dp[i][c][0] = min(dp[i-1][c][0], dp[i-1][c][1]); // unlock excav
      
      
      // we will build at i

      // unexcav left
      int dig = max(a[i-1]-a[i]+1, 0) + max(a[i+1]-a[i]+1, 0);
      dp[i][c][1] = dp[i-1][c-1][0] + dig;
      
      // excav left, where it comes from i-2
      
      if(i >= 3)
      {
        int dig2 = max(min(a[i-2]-1, a[i-1]) - a[i] + 1, 0) + max(a[i+1]-a[i]+1, 0);
        dp[i][c][1] = min(dp[i][c][1], dp[i-2][c-1][1]+dig2);
      }
      //printf("%d, %d: %d, %d\n", i, c, dp[i][c][0], dp[i][c][1]);
    }
  }
  for(int i=1; i<=(N+1)/2; ++i)
    printf("%d ", min(dp[N][i][1], dp[N][i][0]));
  puts("");
}