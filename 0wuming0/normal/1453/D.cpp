#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll dp[1000];
int ans[2005];
int nn;
int main()
{
    dp[0]=2;
    for(int i=1;i<=100;i++)
    {
        dp[i]=dp[i-1]*2+2;
        //cout<<i<<" "<<dp[i]<<endl;
    }
    int T;
    cin>>T;
    while(T--)
    {
        ll n;
        scanf("%lld",&n);
        nn=0;
        if(n&1)
        {
            printf("-1\n");
            continue;
        }
        for(int i=0;i<60;i++)
        {
            if(dp[i]>n)
            {
                while(1)
                {
                    while(n>=dp[i])
                    {
                        n-=dp[i];
                        ans[nn++]=1;
                        for(int k=0;k<i;k++)ans[nn++]=0;
                    }
                    if(n==0)break;
                    i--;
                }
            }
            if(n==0)break;
        }
        printf("%d\n",nn);
        for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
    }
    return 0;
}