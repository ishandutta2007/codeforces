#include<iostream>
#include<algorithm>
using namespace std;

const int N=100005;

long long dp[N], a[N];

int main()
{
    int n;
    scanf("%d",&n);

    a[0]=-1500;

    for(int i=1;i<=n;++i)
        scanf("%lld",a+i);

    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]=20+dp[i-1];

        int x=upper_bound(a,a+n+1,a[i]-90)-a-1;
        dp[i]=min(dp[x]+50,dp[i]);

        x=x=upper_bound(a,a+n+1,a[i]-1440)-a-1;
        dp[i]=min(dp[x]+120,dp[i]);

        printf("%d\n",dp[i]-dp[i-1]);
    }
}