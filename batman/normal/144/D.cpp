#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define INF ((ll)1e9)

ll n,m,a,dis[N],l,ans;
vector <pair<ll,ll> > e[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>a;
    for(int i=0;i<m;i++)
    {
        ll v,u,w;
        cin>>v>>u>>w;
        e[v].push_back({u,w});
        e[u].push_back({v,w});
    }
    cin>>l;
    set <pair<ll,ll> > s;s.insert({0,a});
    for(int i=0;i<N;i++)dis[i]=INF;
    dis[a]=0;
    while(s.size())
    {
        ll x=s.begin()->second;
        s.erase(s.begin());
        for(int i=0;i<e[x].size();i++)
            if(dis[x]+e[x][i].second<dis[e[x][i].first])
                s.erase({dis[e[x][i].first],e[x][i].first}),dis[e[x][i].first]=dis[x]+e[x][i].second,s.insert({dis[e[x][i].first],e[x][i].first});
    }                   
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==l)ans++;
        for(int j=0;j<e[i].size();j++)
            if(e[i][j].first>i)
            {
                if(dis[i]<l && dis[i]+e[i][j].second>l && e[i][j].second-(l-dis[i])+dis[e[i][j].first]>l)
                    ans++;
                if(dis[e[i][j].first]<l && dis[e[i][j].first]+e[i][j].second>l && e[i][j].second-(l-dis[e[i][j].first])+dis[i]>=l)
                    ans++;
            }
    }
    cout<<ans;
    return 0;
}