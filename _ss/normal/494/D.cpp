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
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
vector<pii> G[maxn];
ll n,spr[maxn][20],sprv[maxn][20],h[maxn],f[maxn],g[maxn],sl[maxn],sl2[maxn],g2[maxn],f2[maxn];

void read()
{
    cin>>n;
    int u,v,w;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        G[u].pb(mp(v,w));
        G[v].pb(mp(u,w));
    }
}

ll product(ll obj1,ll obj2) {return ((obj1%mod)*(obj2%mod))%mod;}

void dfs(int u,int k)
{
    h[u]=k;
    for (int i=0;i<G[u].size();i++)
        if (G[u][i].fi!=spr[u][0])
        {
            int v=G[u][i].fi,w=G[u][i].se;
            spr[v][0]=u;
            sprv[v][0]=w;
            for (int j=1;j<20;j++)
            {
                spr[v][j]=spr[spr[v][j-1]][j-1];
                sprv[v][j]=sprv[v][j-1]+sprv[spr[v][j-1]][j-1];
            }
            dfs(v,k+1);
            f[u]=(f[u]+product(product(w,w),sl[v])+f[v]+2*g[v]*w)%mod;
            g[u]=(g[u]+g[v]+sl[v]*w)%mod;
            sl[u]+=sl[v];
        }
    sl[u]++;
}

void dfs2(int u)
{
    for (int i=0;i<G[u].size();i++)
        if (G[u][i].fi!=spr[u][0])
        {
            int v=G[u][i].fi,w=G[u][i].se;
            f[v]=(f[v]+f[u]-product(product(w,w),sl[v])-f[v]-2*g[v]*w+product(product(w,w),sl[u]-sl[v])+2*(g[u]-g[v]-(sl[v]*w)%mod)*w+mod*mod*3)%mod;
            g[v]=(g[v]+g[u]-g[v]-sl[v]*w+(sl[u]-sl[v])*w)%mod;
            sl[v]+=sl[u]-sl[v];
            dfs2(v);
        }
}

pii findp(int x,int k)
{
    ll res=0;
    for (int i=0;k;k>>=1,i++)
        if (k&1)
        {
            res+=sprv[x][i];
            x=spr[x][i];
        }
    return mp(x,res);
}

pii lca(int u,int v)
{
    int tmp=min(h[u],h[v]);
    pii t1=findp(u,h[u]-tmp),t2=findp(v,h[v]-tmp);
    ll res=t1.se+t2.se;
    u=t1.fi;
    v=t2.fi;
    int k=19;
    while (u!=v)
    {
        while (k && spr[u][k]==spr[v][k]) k--;
        res+=sprv[u][k]+sprv[v][k];
        u=spr[u][k];
        v=spr[v][k];
    }
    return mp(u,res);
}

ll query(int u,int v)
{
    pii tmp=lca(u,v);
    ll r=tmp.fi,k=tmp.se;
    if (v==1) return f[u];
    else if (r!=v)
    {
        return (2*(product(product(k,k),sl2[v])+f2[v]+2*product(k,g2[v]))-f[u]+mod*mod)%mod;
    }
    else
    {
        int p=spr[v][0],w=sprv[v][0];
        ll t=(f[p]-product(product(w,w),sl2[v])-f2[v]-2*product(w,g2[v])+mod*mod)%mod,t2=(g[p]-g2[v]-product(w,sl2[v])+mod*mod)%mod;
        k+=w;
        return (mod*mod+f[u]-2*(product(product(k,k),sl[p]-sl2[v])+t+2*product(k,t2)))%mod;
    }
}

void process()
{
    int q;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<query(u,v)<<endl;
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    dfs(1,1);
    for (int i=1;i<=n;i++)
    {
        f2[i]=f[i];
        g2[i]=g[i];
        sl2[i]=sl[i];
    }
    dfs2(1);
    process();
    return 0;
}