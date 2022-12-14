#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll p[100001],dp[100001],i,j,n,m,k;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
     cin >> n;
     for(i=0;i<n;i++)
     {
         ll x;
         cin >> x;
         p[x]++;
     }
     dp[0]=0;
     dp[1]=p[1];
     for(i=2;i<=100000;i++)dp[i]=max(dp[i-1],dp[i-2]+p[i]*i);
     cout << dp[100000] << endl;
   return 0;
}