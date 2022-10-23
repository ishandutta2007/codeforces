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
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;

struct ds
{
    int u,v,r;
};

int n,p[maxn],spr[maxn][20],h[maxn],a[maxn];
ds it[maxn*4];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],p[i]++,a[p[i]]=i;
    h[1]=1;
    for (int i=2;i<=n;i++) cin>>spr[i][0],h[i]=h[spr[i][0]]+1;
}

int la(int u,int k)
{
    for (int i=0;k;k>>=1,i++)
        if (k&1) u=spr[u][i];
    return u;
}

int lca(int u,int v)
{
    int tmp=min(h[u],h[v]);
    u=la(u,h[u]-tmp);
    v=la(v,h[v]-tmp);
    int k=19;
    while (u!=v)
    {
        while (k && spr[u][k]==spr[v][k]) k--;
        u=spr[u][k];
        v=spr[v][k];
    }
    return u;
}

void add_to_path(ds &obj,int x)
{
    if (obj.u==-1) return;
    if (x==-1)
    {
        obj.u=-1;
        return;
    }
    int u=obj.u,v=obj.v,r=obj.r;
    if (h[x]>=h[u])
    {
        int y=la(x,h[x]-h[u]);
        if (y==u)
        {
            obj.u=x;
            return;
        }
    }
    if (v!=r && h[x]>=h[v])
    {
        int y=la(x,h[x]-h[v]);
        if (y==v)
        {
            obj.v=x;
            if (h[obj.u]<h[obj.v]) swap(obj.u,obj.v);
            return;
        }
    }
    if (v==r)
    {
        int check=0;
        if (h[x]<=h[v]) check=1;
        else
        {
            int y=la(x,h[x]-h[v]);
            if (y!=v) check=1;
        }
        if (check)
        {
            obj.v=x;
            if (h[obj.u]<h[obj.v]) swap(obj.u,obj.v);
            obj.r=lca(obj.u,obj.v);
            return;
        }
    }
    if (h[r]<=h[x] && h[x]<=h[u])
    {
        int y=la(u,h[u]-h[x]),z=la(x,h[x]-h[r]);
        if (y==x && z==r) return;
    }
    if (h[r]<=h[x] && h[x]<=h[v])
    {
        int y=la(v,h[v]-h[x]),z=la(x,h[x]-h[r]);
        if (y==x && z==r) return;
    }
    if (v==r)
    {
    int y=lca(u,x);
    if (y==r)
    {
        obj.v=x;
        if (h[obj.u]<h[obj.v]) swap(obj.u,obj.v);
        return;
    }
    }
    obj.u=-1;
    return;
}

ds merg(ds obj1,ds obj2)
{
    ds tmp=obj1;
    add_to_path(tmp,obj2.u);
    add_to_path(tmp,obj2.v);
    return tmp;
}

void build(int st,int l,int r)
{
    if (l==r)
    {
        it[st]={a[l],a[l],a[l]};
        return;
    }
    int mid=(l+r)/2;
    build(st*2,l,mid);
    build(st*2+1,mid+1,r);
    it[st]=merg(it[st*2],it[st*2+1]);
}

void update(int st,int l,int r,int v,int x)
{
    if (l==r)
    {
        it[st]={x,x,x};
        return;
    }
    int mid=(l+r)/2;
    if (v<=mid) update(st*2,l,mid,v,x);
    else update(st*2+1,mid+1,r,v,x);
    ds tmp=merg(it[st*2],it[st*2+1]);
    it[st]=tmp;
}

int query(int st,int l,int r,ds v)
{
    if (l==r)
    {
        ds tmp=merg(v,it[st]);
        if (tmp.u!=-1) return l;
        return l-1;
    }
    ds tmp=merg(v,it[st*2]);
    int mid=(l+r)/2;
    if (tmp.u==-1) return query(st*2,l,mid,v);
    return query(st*2+1,mid+1,r,tmp);
}

void process()
{
    for (int i=2;i<=n;i++)
        for (int k=1;k<20;k++) spr[i][k]=spr[spr[i][k-1]][k-1];
    build(1,1,n);
    int q,t,u,v;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>t;
        if (t==1)
        {
            cin>>u>>v;
            update(1,1,n,p[u],v);
            update(1,1,n,p[v],u);
            swap(p[u],p[v]);
            a[p[u]]=u;
            a[p[v]]=v;
        }
        else cout<<query(1,1,n,{a[1],a[1],a[1]})<<endl;
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