#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define INF ((ll)1e16)

ll n,m,k,d[N],a[N],ans;
bool last[N];
vector <pair<ll,pair<ll,bool> > > e[N];
vector <ll> in;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        ll v,u,w;
        cin>>v>>u>>w;
        e[v].push_back({u,{w,0}});
        e[u].push_back({v,{w,0}});
    }
    for(int i=0;i<k;i++)
    {
        ll w;
        cin>>a[i]>>w;
        if(last[a[i]])ans++;
        else in.push_back(a[i]);
        last[a[i]]=1;
        e[1].push_back({a[i],{w,1}});
        e[a[i]].push_back({1,{w,1}});
    }
    for(int i=0;i<N;i++)d[i]=INF;
    d[1]=0;
    set <pair<ll,ll> > s;s.insert({0,1});
    while(s.size())
    {
        ll x=s.begin()->second;s.erase(s.begin());
        for(int i=0;i<e[x].size();i++)
            if(d[x]+e[x][i].second.first<d[e[x][i].first] || (d[x]+e[x][i].second.first==d[e[x][i].first] && last[e[x][i].first] && !e[x][i].second.second))
            {
                last[e[x][i].first]=e[x][i].second.second;
                s.erase({d[e[x][i].first],e[x][i].first}),d[e[x][i].first]=d[x]+e[x][i].second.first,s.insert({d[e[x][i].first],e[x][i].first});
            }
    }
    for(int i=0;i<in.size();i++)
        if(!last[in[i]])
            ans++;
    cout<<ans;
    return 0;
}