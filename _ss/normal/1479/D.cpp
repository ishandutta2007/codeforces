#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) { return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N=3e5+3,lgn=20;
const ll MxV=3e12;

struct node
{
    int lef,rig;
    ll val;
};

struct PIT
{
    node it[N*40];
    int sl=1,sz;

    void combine(int id)
    {
        int lef=it[id].lef,rig=it[id].rig;
        it[id].val=it[lef].val+it[rig].val;
    }

    void build(int id,int l,int r)
    {
        sl=max(sl,id+1);
        if (l==r) return;
        int mid=(l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        it[id].lef=id*2;
        it[id].rig=id*2+1;
    }

    void inp(int len)
    {
        build(1,1,len);
        sz=len;
    }

    int add(int id,int l,int r,int v,ll x)
    {
        if (l==r)
        {
            it[sl++]=it[id];
            if (it[sl-1].val==x) it[sl-1]={0,0,0};
            else it[sl-1]={0,0,x};
            return sl-1;
        }
        int mid=(l+r)>>1,ne=sl++;
        it[ne]=it[id];
        if (v<=mid) it[ne].lef=add(it[id].lef,l,mid,v,x);
        else it[ne].rig=add(it[id].rig,mid+1,r,v,x);
        combine(ne);
        return ne;
    }

    ll query(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return it[id].val;
        int mid=(l+r)>>1,lef=it[id].lef,rig=it[id].rig;
        return query(lef,l,mid,u,v)+query(rig,mid+1,r,u,v);
    }

    int lcp(int id1,int id2,int l,int r,int u,int v)
    {
        if (l>v || r<u || it[id1].val==it[id2].val) return -1;
        if (l==r) return l;
        int mid=(l+r)>>1;
        int tmp=lcp(it[id1].lef,it[id2].lef,l,mid,u,v);
        if (tmp!=-1) return tmp;
        return lcp(it[id1].rig,it[id2].rig,mid+1,r,u,v);
    }

    int addver(int root,int pos,ll x) {return add(root,1,sz,pos,x);}
    ll get(int root,int l,int r) {return query(root,1,sz,l,r);}
    int dif(int id1,int id2,int l,int r) {return lcp(id1,id2,1,sz,l,r);}
} seg;

ll val[N];
vi G[N];
int ver[N],n,a[N];
int h[N],spr[N][22];

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
    int k=lgn;
    while (u!=v)
    {
        while (k && spr[u][k]==spr[v][k]) k--;
        u=spr[u][k];
        v=spr[v][k];
    }
    return u;
}

void dfs(int u,int r,int k)
{
    h[u]=k;
    for (int t=1;t<=lgn;t++) spr[u][t]=spr[spr[u][t-1]][t-1];
    for (int v : G[u])
        if (v!=r)
        {
            ver[v]=seg.addver(ver[u],a[v],val[a[v]]);
            spr[v][0]=u;
            dfs(v,u,k+1);
        }
}

int q;
void read()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].eb(v);
        G[v].eb(u);
    }
}

int findval(int st,int en,int u,int v)
{
    return seg.dif(ver[u],ver[v],st,en);
}

int solve(int st,int en,int u,int v)
{
    int r=lca(u,v);
    if (st<=a[r] && a[r]<=en)
    {
        int tmp=findval(st,a[r]-1,u,v);
        if (tmp!=-1) return tmp;
        tmp=findval(a[r]+1,en,u,v);
        if (tmp!=-1) return tmp;
        tmp=findval(a[r],a[r],u,v);
        if (tmp==-1) return a[r];
        return -1;
    }
    return findval(st,en,u,v);
}

void process()
{
    for (int i=1;i<=n;i++) val[i]=Int(1,MxV);
    seg.inp(n);
    ver[1]=1;
    dfs(1,0,0);
    for (int i=1,l,r,u,v;i<=q;i++)
    {
        cin>>u>>v>>l>>r;
        cout<<solve(l,r,u,v)<<"\n";
    }
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