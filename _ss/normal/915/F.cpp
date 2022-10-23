#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e6+10,mod=1e9+7,inf=1e18;
vector<int> G[maxn];
pii a[maxn];
int n,p[maxn],active[maxn];
ll siz[maxn];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        //cin>>a[i].fi;
        scanf("%I64d",&a[i].fi);
        a[i].se=i;
    }
    int u,v;
    for (int i=1;i<n;i++)
    {
        //cin>>u>>v;
        scanf("%d %d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
}

int findroot(int u)
{
    if (p[u]>0)
    {
        p[u]=findroot(p[u]);
        return p[u];
    }
    return u;
}

void merg(int u,int v)
{
    if (u<v) p[v]=u,siz[u]+=siz[v];
    else if (u>v) p[u]=v,siz[v]+=siz[u];
    else
    {
        p[v]=u,siz[u]+=siz[v];
        p[u]--;
    }
}

void process()
{
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) siz[i]=1;
    ll res1=0,res2=0;
    for (int i=1;i<=n;i++)
    {
        int u=a[i].se;
        active[u]=1;
        for (int j=0;j<G[u].size();j++)
            if (active[G[u][j]])
            {
                int v=G[u][j];
                int ru=findroot(u),rv=findroot(v);
                res1+=siz[rv]*siz[ru]*a[i].fi;
                merg(ru,rv);
            }
    }
    for (int i=1;i<=n;i++) p[i]=0,siz[i]=1,active[i]=0;
    for (int i=n;i;i--)
    {
        int u=a[i].se;
        active[u]=1;
        for (int j=0;j<G[u].size();j++)
            if (active[G[u][j]])
            {
                int v=G[u][j];
                int ru=findroot(u),rv=findroot(v);
                res2+=siz[rv]*siz[ru]*a[i].fi;
                merg(ru,rv);
            }
    }
    cout<<res1-res2;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    read();
    process();
    return 0;
}