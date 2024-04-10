#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,V=1e7,lgn=16;
const ll mod=1e9+7;
int lp[V+10];

void sieve()
{
    for (int i=2;i<=V;i++)
        if (!lp[i])
            for (int j=i;j<=V;j+=i)
                if (!lp[j]) lp[j]=i;
}

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

struct ds{int u,v,x,id,r;};
int n,q,spr[N][20],h[N],st[N],en[N],tim=0;
vector<int> G[N];
ll ans[N],bit[N];
vector<pii> upd[V+10];
vector<ds> que[V+10];

void read()
{
    cin>>n;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        while (lp[x])
        {
            int k=lp[x],d=0;
            while (lp[x]==k)
            {
                x/=k;
                d++;
                upd[k].pb(mp(d,i));
            }
        }
    }
}

void dfs(int u,int r,int k)
{
    tim++;
    st[u]=tim;
    h[u]=k;
    for (int i=1;i<=lgn;i++) spr[u][i]=spr[spr[u][i-1]][i-1];
    for (int v : G[u])
        if (v!=r)
        {
            spr[v][0]=u;
            dfs(v,u,k+1);
        }
    en[u]=tim;
}

int findp(int u,int x)
{
    for (int i=0;x;x/=2,i++)
        if (x&1) u=spr[u][i];
    return u;
}

int lca(int u,int v)
{
    int tmp=min(h[u],h[v]);
    u=findp(u,h[u]-tmp);
    v=findp(v,h[v]-tmp);
    int k=17;
    while (u!=v)
    {
        while (k && spr[u][k]==spr[v][k]) k--;
        u=spr[u][k];
        v=spr[v][k];
    }
    return u;
}

void add(int v,int x)
{
    for (int i=v;i<=n;i+=(i&-i)) bit[i]=bit[i]*x%mod;
}

ll get(int v)
{
    ll res=1;
    for (int i=v;i;i-=(i&-i)) res=res*bit[i]%mod;
    return res;
}

void solve(int x)
{
    for (int i=1;i<=n;i++) bit[i]=1;
    int j=0;
    ll ix=inverse(x);
    for (ds t : que[x])
    {
        while (j<(int)upd[x].size() && upd[x][j].fi<=t.x)
        {
            int id=upd[x][j].se;
            add(st[id],x);
            add(en[id]+1,ix);
            j++;
        }
        ans[t.id]=ans[t.id]*get(st[t.u])%mod*get(st[t.v])%mod*inverse(get(st[t.r]))%mod;
        if (t.r!=1) ans[t.id]=ans[t.id]*inverse(get(st[spr[t.r][0]]))%mod;
    }
}

bool cmp(ds t1,ds t2) {return t1.x<t2.x; }

void process()
{
    dfs(1,0,1);
    cin>>q;
    for (int i=1,u,v,x;i<=q;i++)
    {
        cin>>u>>v>>x;
        int r=lca(u,v);
        while (lp[x])
        {
            int k=lp[x],d=0;
            while (lp[x]==k)
            {
                x/=k;
                d++;
            }
            que[k].pb({u,v,d,i,r});
        }
        ans[i]=1;
    }
    for (int i=2;i<=V;i++)
        if (lp[i]==i)
        {
            sort(all(upd[i]));
            sort(all(que[i]),cmp);
        }
    for (int i=2;i<=V;i++)
        if (upd[i].size() && que[i].size()) solve(i);
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    read();
    process();
    return 0;
}