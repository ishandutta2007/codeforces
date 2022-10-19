#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
ll mod;
ll dp[4000005];
ll sum[4000005];
void ins(int p,ll x)
{/*
    int pl=1;
    int pr=4000000;
    int now=1;
    while(1)
    {
        dp[now]+=x;
        dp[now]%=mod;//cout<<now<<" "<<dp[now]<<endl;
        if(pl==pr)break;
        int m=pl+pr>>1;
        if(p<=m)
        {
            now<<=1;
            pr=m;
        }
        else
        {
            now<<=1;
            now++;
            pl=m+1;
        }
    }*/
    dp[p]=x;
    sum[p]=sum[p+1]+dp[p];
}
ll get(int now,int pl,int pr,int l,int r)
{/*
    if(pl==l&&pr==r)
    {
        return dp[now];
    }
    int x=pl+pr>>1;
    if(x>=r)
    {
        return get(now*2,pl,x,l,r);
    }
    else if(x<l)
    {
        return get(now*2+1,x+1,pr,l,r);
    }
    else
    {
        return (get(now*2,pl,x,l,x)+get(now*2+1,x+1,pr,x+1,r))%mod;
    }*/
    return ((sum[l]-sum[r+1])%mod+mod)%mod;
}
int main()
{
    int n;
    cin>>n>>mod;
    ins(n,1);//cout<<get(1,1,4000000,n,n)<<endl;
    for(int i=n-1;i>=1;i--)
    {
        ll ans=get(1,1,4000000,i+1,n);
        for(int j=2;i*j<=n;j++)
        {
            ans+=get(1,1,4000000,i*j,min(i*j+j-1,n));
            ans%=mod;
        }//cout<<i<<" "<<ans<<endl;
        ins(i,ans);
    }
    cout<<get(1,1,4000000,1,1)<<endl;
    return 0;
}
/*
4000000 100000007
*/