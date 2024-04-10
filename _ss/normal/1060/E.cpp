#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;
vector<int> G[N];
ll sl[N],p[N],a[N],res=0,n;

void read()
{
    cin>>n;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int u)
{
    sl[u]=1;
    for (int v : G[u])
        if (v!=p[u])
        {
            a[v]=a[u]^1;
            p[v]=u;
            dfs(v);
            res+=sl[u]*sl[v];
            sl[u]+=sl[v];
        }
    res+=sl[u]*(n-sl[u]);
}

void process()
{
    dfs(1);
    res=res-n*(n-1)/2;
    ll sl1=0;
    for (int i=1;i<=n;i++)
        if (a[i]) sl1++;
    cout<<(res-sl1*(n-sl1))/2+sl1*(n-sl1);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}