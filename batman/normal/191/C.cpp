#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
#define K (60)
#define ll long long
#define INF ((ll)1e9)

ll n,q,par[N][K],dis[N],dp[N],cnt,ans[N];
vector <ll> e[N];
map <pair<ll,ll>,pair<ll,ll> > mp;

void build(ll x)
{
    for(int i=1;i<K;i++)
        par[x][i]=par[par[x][i-1]][i-1];
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=par[x][0])
            par[e[x][i]][0]=x,dis[e[x][i]]=dis[x]+1,build(e[x][i]);
}

ll iPar(ll x,ll num)
{
    for(int i=0;i<K;i++,num/=2)
        if(num%2)
            x=par[x][i];
    return x;       
}

ll cPar(ll x,ll y)
{
    if(dis[x]<dis[y])swap(x,y);
    x=iPar(x,dis[x]-dis[y]);
    if(x==y)return x;
    for(int i=K-1;i>=0;i--)
        if(par[x][i]!=par[y][i])
            x=par[x][i],y=par[y][i];
    return par[x][0];
}

void dfs(ll x,ll y=0)
{
    ll cnt2=cnt;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=y)
        {
            cnt=0;
            dfs(e[x][i],x);
            cnt2+=cnt;
        }
    cnt=cnt2;   
    cnt+=dp[x];     
    if(!y)return ;
    mp[{x,y}].second=mp[{y,x}].second=cnt;      
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);
        mp[{v,u}].first=mp[{u,v}].first=i;
    }
    build(1);
    cin>>q;
    while(q--)
    {
        ll v,u;
        cin>>v>>u;
        dp[v]++,dp[u]++,dp[cPar(v,u)]-=2;
    }
    dfs(1);
    for(map <pair<ll,ll>,pair<ll,ll> >::iterator it=mp.begin();it!=mp.end();it++)
        ans[it->second.first]=it->second.second;
    for(int i=0;i<n-1;i++)cout<<ans[i]<<" ";    
    return 0;
}