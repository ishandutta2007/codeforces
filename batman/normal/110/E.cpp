#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e9)

ll n,ans,cnt[N],dp_down[N],dp_up[N];
vector <pair <ll,bool> > e[N];

void dfs2(ll x,ll par=0)
{
    for(int i=0;i<e[x].size();i++)
        if(e[x][i].first!=par)
        {
            if(e[x][i].second)dp_up[e[x][i].first]=n-cnt[e[x][i].first];
            else dp_up[e[x][i].first]=dp_up[x]+dp_down[x]-dp_down[e[x][i].first];
            dfs2(e[x][i].first,x);
        }
}

void dfs(ll x,ll par=0)
{
    cnt[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i].first!=par)
        {
            dfs(e[x][i].first,x);
            cnt[x]+=cnt[e[x][i].first];
            if(e[x][i].second)dp_down[x]+=cnt[e[x][i].first];
            else dp_down[x]+=dp_down[e[x][i].first];
        }
}

int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll v,u,w;
        cin>>v>>u>>w;
        bool p=1;
        while(w){if(w%10!=4 && w%10!=7)p=0;w/=10;}
        e[v].push_back({u,p});
        e[u].push_back({v,p});
    }
    dfs(1);dfs2(1);
    for(int i=1;i<=n;i++)
        ans+=(dp_down[i]+dp_up[i])*(dp_down[i]+dp_up[i]-1);
    cout<<ans;  
    return 0;
}