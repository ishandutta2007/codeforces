#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n, ans=1;
int a[N+1], dp[N+1];

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      dp[a[i]]=1;
   }
   for(int i=N;i>=1;i--)
   {
      if(!dp[i])
         continue;
      for(int j=2*i;j<=N;j+=i)
      {
         dp[i]=max(dp[i], 1+dp[j]);
         ans=max(ans, dp[i]);
      }
   }
   cout<<ans;
}