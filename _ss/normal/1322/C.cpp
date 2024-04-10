#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
const ll base=784697,mod=1e9+9;
int n,m;
ll val[N];
vector<int> G[N];

ll gcd(ll t1,ll t2)
{
    while (t2)
    {
        ll tmp=t1%t2;
        t1=t2;
        t2=tmp;
    }
    return t1;
}

void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>val[i],G[i].clear();
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        G[v].pb(u);
    }
}

void process()
{
    map<pii,ll> can;
    ll res=0;
    for (int i=1;i<=n;i++)
    {
        sort(all(G[i]));
        ll h=0;
        for (ll x : G[i]) h=(h*base+x)%mod;
        if (G[i].size()>0) can[mp(G[i].size(),h)]+=val[i];
        //if (G[i].size()>0) can[G[i]]+=val[i];
    }
    for (auto ir=can.begin();ir!=can.end();ir++)
    {
        ll tmp=ir->se;
        res=gcd(res,tmp);
    }
    cout<<res<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}