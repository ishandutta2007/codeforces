#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=4e5+10,inf=2e9;

struct segment_tree
{
    int it[N*4],lazy[N*4];

    int combine(int t1,int t2)
    {
        return max(t1,t2);
    }

    void build(int a[], int id,int l,int r)
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

    void down(int id)
    {
        int tmp=lazy[id];
        it[id*2]+=tmp;
        it[id*2+1]+=tmp;
        lazy[id*2]+=tmp;
        lazy[id*2+1]+=tmp;
        lazy[id]=0;
    }

    void update_range(int id,int l,int r,int u,int v,int x)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            it[id]+=x;
            lazy[id]+=x;
            return;
        }
        down(id);
        int mid=(l+r)>>1;
        update_range(id*2,l,mid,u,v,x);
        update_range(id*2+1,mid+1,r,u,v,x);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    int get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return it[id];
        down(id);
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }

};

struct ds {int x,y,z;};
ds mo[N];
pii w[N],ar[N];
int n,m,p,val[N];

void read()
{
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++) scanf("%d %d",&w[i].fi,&w[i].se);
    for (int i=1;i<=m;i++) scanf("%d %d",&ar[i].fi,&ar[i].se);
    for (int i=1;i<=p;i++) scanf("%d %d %d",&mo[i].x,&mo[i].y,&mo[i].z);
}

bool cmp(ds t1,ds t2) { return t1.x<t2.x; }
segment_tree seg;

void add(int id)
{
    int vt=upper_bound(ar+1,ar+m+1,mp(mo[id].y,inf))-ar;
    if (vt<=m) seg.update_range(1,1,m,vt,m,mo[id].z);
}

void process()
{
    sort(w+1,w+n+1);
    sort(ar+1,ar+m+1);
    sort(mo+1,mo+p+1,cmp);
    for (int i=1;i<=m;i++) val[i]=-ar[i].se;
    seg.build(val,1,1,m);
    int res=-inf;
    int j=1;
    for (int i=1;i<=n;i++)
    {
        while (j<=p && mo[j].x<w[i].fi)
        {
            add(j);
            j++;
        }
        res=max(res,seg.get(1,1,m,1,m)-w[i].se);
    }
    cout<<res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}