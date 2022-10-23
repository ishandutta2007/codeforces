#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,inf=1e9;

struct segment_tree
{
    pii it[N*4];

    pii combine(pii t1,pii t2)
    {
        return min(t1,t2);
    }

    void build(pii a[], int id,int l,int r)
    {
        if (l==r)
        {
            it[id]=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(a,id*2,l,mid);
        build(a,id*2+1,mid+1,r);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    void update(int id,int l,int r,int v,int x)
    {
        if (l==r)
        {
            it[id].fi=x;
            return;
        }
        int mid=(l+r)>>1;
        if (v<=mid) update(id*2,l,mid,v,x);
        else update(id*2+1,mid+1,r,v,x);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    pii get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return mp(inf,0);
        if (u<=l && r<=v) return it[id];
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }

} seg;

int n,bit[N];
pii a[N];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi,a[i].se=i;
}

void add(int v,int x)
{
    for (int i=v;i<=n;i+=(i&-i)) bit[i]+=x;
}

int getv(int v)
{
    int res=0;
    for (int i=v;i;i-=(i&-i)) res+=bit[i];
    return res;
}

void process()
{
    seg.build(a,1,1,n);
    int l=1;
    ll res=0;
    for (int i=1;i<=n;i++) add(i,1);
    for (int i=1;i<=n;i++)
    {
        pii v1=seg.get(1,1,n,1,n),v2=seg.get(1,1,n,l,n);
        if (v1.fi==v2.fi)
        {
            seg.update(1,1,n,v2.se,inf);
            res+=getv(v2.se)-getv(l-1);
            l=v2.se+1;
            add(v2.se,-1);
            if (l>n) l=1;
        }
        else
        {
            seg.update(1,1,n,v1.se,inf);
            res+=(n-i+1)-getv(l-1)+getv(v1.se);
            l=v1.se+1;
            add(v1.se,-1);
            if (l>n) l=1;
        }
    }
    cout<<res;
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