#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main()
{
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    vector<ll> v(m,0);
    for(int i=0;i<m;i++) scanf("%I64d",&v[i]);
    sort(v.begin(),v.end());
    ll g,r;
    scanf("%I64d%I64d",&g,&r);
    if(v[m-1]-v[0]<=g)
    {
        printf("%I64d\n",g);
        return 0;
    }
    const ll inf=(1ll<<60);
    vector<vector<ll>> dp(m,vector<ll>(g,inf));
    dp[0][0]=0;
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q; //r,island,x
    q.push({0,0,0});
    while(!q.empty())
    {
        auto [t,i,x]=q.top();
        q.pop();
        if(dp[i][x]<t) continue;
        if(i>0)
        {
            ll d=v[i]-v[i-1];
            if(x+d<g&&dp[i][x]<dp[i-1][x+d])
            {
                dp[i-1][x+d]=dp[i][x];
                q.push({dp[i-1][x+d],i-1,x+d});
            }
            if(x+d==g&&dp[i][x]+1<dp[i-1][0])
            {
                dp[i-1][0]=dp[i][x]+1;
                q.push({dp[i-1][0],i-1,0});
            }
        }
        if(i<m-1)
        {
            ll d=v[i+1]-v[i];
            if(x+d<g&&dp[i][x]<dp[i+1][x+d])
            {
                dp[i+1][x+d]=dp[i][x];
                q.push({dp[i+1][x+d],i+1,x+d});
            }
            if(x+d==g&&dp[i][x]+1<dp[i+1][0])
            {
                dp[i+1][0]=dp[i][x]+1;
                q.push({dp[i+1][0],i+1,0});
            }
        }
    }
    ll res=inf;
    for(ll i=0;i<g;i++)
    {
        if(dp[m-1][i]==inf) continue;
        if(i==0) res=min(res,dp[m-1][i]*g+(dp[m-1][i]-1)*r+i);
        else res=min(res,dp[m-1][i]*(g+r)+i);
    }
    if(res!=inf) printf("%I64d\n",res);
    else printf("-1\n");
    return 0;
}