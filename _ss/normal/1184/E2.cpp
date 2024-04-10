#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1,maxint=1e9;

struct edge
{
    ll u,v,w,st;
};

edge a[maxn*10];
ll n,m,p[maxn],mark[maxn*10],sp[20][maxn],spv[20][maxn],h[maxn],aans[maxn*10];
vector<pii> G[maxn];

void read()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++) scanf("%I64d %I64d %I64d",&a[i].u,&a[i].v,&a[i].w),a[i].st=i;
}

bool cmp(edge t1, edge t2)
{
    return t1.w<t2.w;
}

int findroot(int u)
{
    while (p[u]>0) u=p[u];
    return u;
}

void megh(int u,int v)
{
    if (p[u]<p[v]) p[v]=u;
    else if (p[v]<p[u]) p[u]=v;
    else
    {
        p[v]=u;
        p[u]--;
    }
}

void mst()
{
    int t=0;
    for (int i=1;i<=m && t<n;i++)
    {
        int u=a[i].u,v=a[i].v,w=a[i].w,ru=findroot(u),rv=findroot(v);
        if (ru!=rv)
        {
            t++;
            megh(ru,rv);
            G[u].pb({v,w});
            G[v].pb({u,w});
            mark[i]=1;
            aans[a[i].st]=-1;
        }
    }
}

void dfs(int u,int k)
{
    h[u]=k;
    for (int i=0;i<G[u].size();i++)
        if (!sp[0][G[u][i].fi] && G[u][i].fi!=1)
        {
            int v=G[u][i].fi,w=G[u][i].se;
            sp[0][v]=u;
            spv[0][v]=w;
            dfs(v,k+1);
        }
}

pii findp(int u,int k)
{
    ll ans=-maxint;
    for (int i=0;k;i++,k/=2)
        if (k&1)
        {
            ans=max(ans,spv[i][u]);
            u=sp[i][u];
        }
    return {u,ans};
}

ll lca(int u,int v)
{
    int tmp=min(h[u],h[v]);
    pii pu=findp(u,h[u]-tmp),pv=findp(v,h[v]-tmp);
    ll ans=max(pu.se,pv.se),k=17;
    u=pu.fi,v=pv.fi;
    while (u!=v)
    {
        while (k && sp[k][u]==sp[k][v]) k--;
        ans=max(ans,max(spv[k][u],spv[k][v]));
        u=sp[k][u];
        v=sp[k][v];
    }
    return ans;
}

void process()
{
    sort(a+1,a+m+1,cmp);
    mst();
    for (int k=1;k<=17;k++)
        for (int i=1;i<=n;i++) spv[k][i]=-maxint;
    dfs(1,1);
    for (int k=1;k<=17;k++)
        for (int i=1;i<=n;i++)
        {
            sp[k][i]=sp[k-1][sp[k-1][i]];
            spv[k][i]=max(spv[k-1][i],spv[k-1][sp[k-1][i]]);
        }
    for (int i=1;i<=m;i++)
        if (!mark[i])
        {
            ll tmp=lca(a[i].u,a[i].v);
            aans[a[i].st]=tmp;
        }
    for (int i=1;i<=m;i++)
        if (aans[i]!=-1) printf("%I64d \n",aans[i]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}