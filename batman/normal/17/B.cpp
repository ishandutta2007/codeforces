#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (1100)
#define INF ((ll)1e9)

ll n,m,par[N],ans;
vector <pair <ll,pair<ll,ll> > > ed;
bool mark[N];

ll root(ll x){if(par[x]<0)return x;return par[x]=root(par[x]);}
void merge(ll x,ll y){x=root(x);y=root(y);par[x]=y;}


int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)par[i]=-i,cin>>m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        ed.push_back({w,{u,v}});
    }
    sort(ed.begin(),ed.end());
    for(int i=0;i<ed.size();i++)
    {
        ll u=ed[i].second.first;
        ll v=ed[i].second.second;
        ll w=ed[i].first;
        if(root(u)!=root(v) && !mark[v])
        {
            mark[v]=1;
            ans+=w;
            merge(u,v);
        }
    }
    ll r=root(1);
    for(int i=2;i<=n;i++)
        if(root(i)!=r)
            return cout<<-1,0;
    cout<<ans;
    return 0;
}