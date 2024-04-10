#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=300005,INF=999999999;

int n;
int a[N];

int dp[N][42];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]=a[i]/100;
    }
    for(int i=0;i<=n;++i)for(int j=0;j<=40;++j)dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=40;++j)
        {
            if(j+a[i]/10<=40)
                dp[i][j+a[i]/10]=min(dp[i][j+a[i]/10],dp[i-1][j]+a[i]);
            if(j>=a[i])
                dp[i][j-a[i]]=min(dp[i][j-a[i]],dp[i-1][j]);
            else
                dp[i][0]=min(dp[i][0],dp[i-1][j]+a[i]-j);
        }
    }
    int minu=INF;
    for(int j=0;j<=40;++j)
        minu=min(minu,dp[n][j]);
    cout<<minu*100;
    return 0;
}