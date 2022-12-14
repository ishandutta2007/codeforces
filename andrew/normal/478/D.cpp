#include <bits/stdc++.h>
#define ll int

using namespace std;
ll dp[3][200001],ans=1000000007,i,j,l,n,m,k,sc;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll a,b,r,g;
    cin >> a >> b;
    r=a;
    g=b;
    sc=1;
    if(g>0)dp[0][0]=1;
    if(r>0)dp[0][1]=1;
    for(i=2;i<999;i++)
    {
   //     for(j=0;j<=r;j++)
    //    {
     //       swap(dp[0][j],dp[1][j]);
      //      dp[1][j]=0;
        //    cout << dp[0][j] << " " ;
       // }
       // cout << endl;
        ll fl=0;
        //ll otvet=0;
       for(j=0;j<=r;j++)
       {

         ll k=sc-j;
         k=g-k;
         if(k>=i)dp[1][j]+=dp[0][j];
         if(r-j>=i and j+i<=200000)dp[1][j+i]+=dp[0][j];
         dp[1][j]=dp[1][j]%1000000007;
         if(dp[1][j]>0)fl=1;
         dp[2][j]=dp[0][j];
         dp[0][j]=dp[1][j];
         dp[1][j]=0;
         //otvet=(otvet+dp[2][j])%ans;
       }
       if(fl==0)
       {
           long long  otvet=0;
         //  for(j=0;j<=r;j++)swap(dp[0][j],dp[1][j]);
         for(j=0;j<=r;j++)otvet=(otvet+dp[2][j])%ans;//,cout << dp[1][j] << " "; cout << endl;
         cout << otvet << endl;
           break;
       }
       sc+=i;
       //cout << i << endl;
    }
    return 0;
}