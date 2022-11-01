#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (201*1000)
#define ll long long
#define ld long double
ll gcd1(ll a, ll b) {
    while(b) {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}
ll n,a[N],sum;
vector <ll> e[N];
pair <ll,ll> dp[N];

void dfs(ll x,ll par)
{
    dp[x].second=1;
    ll mini=INF,p=0;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par)
        {
            p++;
            dfs(e[x][i],x);
            if(!dp[e[x][i]].first)
            {
                dp[x]={0,1};
                return ;
            }
            mini=min(mini,dp[e[x][i]].first);
            dp[x].second=dp[x].second*dp[e[x][i]].second/gcd1(dp[x].second,dp[e[x][i]].second);
        }
    if(!p)
    {
        dp[x]={a[x],1};
        return ;
    }
    dp[x].first=((ll)mini/dp[x].second)*dp[x].second*p;
    dp[x].second*=p;
            
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    for(int i=0;i<n-1;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(1,0);
    cout<<sum-dp[1].first;
    
    return 0;
}