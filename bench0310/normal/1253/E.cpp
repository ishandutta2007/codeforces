#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int x[n],s[n];
    for(int i=0;i<n;i++) scanf("%d%d",&x[i],&s[i]);
    int dp[m+1];
    dp[m]=0;
    for(int i=m-1;i>=0;i--)
    {
        dp[i]=m-i;
        for(int j=0;j<n;j++)
        {
            int l,r,t;
            tie(l,r,t)=make_tuple(x[j]-s[j],x[j]+s[j],x[j]-s[j]-i-1);
            if(l<=i+1&&i+1<=r) dp[i]=min(dp[i],dp[i+1]);
            else if(i<l) dp[i]=min(dp[i],dp[min(m,r+t)]+t);
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}