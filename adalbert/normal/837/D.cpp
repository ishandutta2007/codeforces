#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld  long double
typedef long long ll;
///-------------------///

int dp[10][210][6000],c5[1000],c2[1000];

///---program start---///
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        while (a%ll(5)==0 && a!=0)
        {
            c5[i]++;
            a/=ll(5);
        }
        while (a%ll(2)==0 && a!=0)
        {
            c2[i]++;
            a/=ll(2);
        }
    }
    dp[0][0][0]=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<=k;j++)
            for (int t5=0;t5<=29*n;t5++)
                if (dp[i%2][j][t5]!=0)
                {
                    dp[(i+1)%2][j+1][t5+c5[i+1]]=max(dp[(i+1)%2][j+1][t5+c5[i+1]],dp[i%2][j][t5]+c2[i+1]);
                    dp[(i+1)%2][j][t5]=max(dp[(i+1)%2][j][t5],dp[i%2][j][t5]);
                    dp[i%2][j][t5]=0;
                }
    int ans=0;
    for (int t5=0;t5<=29*n;t5++)
        ans=max(ans,min(t5,dp[n%2][k][t5]-1   ));
    cout<<ans;
}