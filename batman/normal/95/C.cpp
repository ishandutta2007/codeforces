#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (1010)
#define INF ((ll)1e16)

ll n,m,g,h,d[N],c[N];
vector <pair<ll,ll> > e[N];
vector <ll> e2[N];


int main()
{
    cin>>n>>m>>g>>h;
    for(int i=0;i<m;i++)
    {
        ll v,u,w;
        cin>>v>>u>>w;
        e[v].push_back({u,w});
        e[u].push_back({v,w});
    }
    for(int p=1;p<=n;p++)
    {
        ll t;
        cin>>t>>c[p];
        for(int i=0;i<N;i++)d[i]=INF;
        d[p]=0;
        set <pair<ll,ll> > s;s.insert({0,p});
        while(s.size())
        {
            ll x=s.begin()->second;s.erase(s.begin());
            for(int i=0;i<e[x].size();i++)
                if(d[e[x][i].first]>d[x]+e[x][i].second)
                    s.erase({d[e[x][i].first],e[x][i].first}),d[e[x][i].first]=d[x]+e[x][i].second,s.insert({d[e[x][i].first],e[x][i].first});
        }
        for(int i=1;i<=n;i++)
            if(i!=p && d[i]<=t)
                e2[p].push_back(i);
    }
    for(int i=0;i<N;i++)d[i]=INF;
    d[g]=0;
    set <pair<ll,ll> > s;s.insert({0,g});
    while(s.size())
    {
        ll x=s.begin()->second;s.erase(s.begin());
        for(int i=0;i<e2[x].size();i++)
            if(d[e2[x][i]]>d[x]+c[x])
                s.erase({d[e2[x][i]],e2[x][i]}),d[e2[x][i]]=d[x]+c[x],s.insert({d[e2[x][i]],e2[x][i]});
    }
    cout<<((d[h]>=INF)?-1:d[h]);
    return 0;
}