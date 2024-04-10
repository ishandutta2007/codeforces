#include"bits/stdc++.h"
using namespace std;
int dp[100005][21];
int a[100005];
int can[2000006];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int j=0;j<21;j++)
    {
        dp[n+1][j]=n+1;
        for(int i=n;i>=1;i--)
        {
            if((1<<j)&a[i])dp[i][j]=i;
            else dp[i][j]=dp[i+1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int now=a[i];
        int pos=i;
        while(pos!=n+1)
        {//cout<<"<<<"<<i<<" "<<now<<" "<<pos<<endl;
            can[now]=1;
            int aim=n+1;
            for(int j=0;j<21;j++)if((now&(1<<j))==0)aim=min(dp[pos][j],aim);
            pos=aim;//cout<<aim<<endl;
            now|=a[pos];
        }
    }
    int ans=0;
    for(int i=0;i<2000006;i++)ans+=can[i];
    cout<<ans<<endl;
    return 0;
}