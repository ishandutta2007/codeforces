#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=2e5+10,siz=320,inf=1e9;

struct segment_tree
{
    int it[N*4];

    void update(int id,int l,int r,int v,int x)
    {
        if (l==r)
        {
            it[id]=x;
            return;
        }
        int mid=(l+r)>>1;
        if (v<=mid) update(id*2,l,mid,v,x);
        else update(id*2+1,mid+1,r,v,x);
        it[id]=min(it[id*2],it[id*2+1]);
    }

    int get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return inf;
        if (u<=l && r<=v) return it[id];
        int mid=(l+r)>>1;
        return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} seg;

int a[N],ps[N][siz*2+10],mxid[N],val[N/siz+10][N],L[N],R[N],n,belong[N],pre[N],vt[N/siz+10][siz*2+10],tim=0;
vector<pii> query[N];
vector<int> spe[N/siz+10];

void build(int id)
{
    for (int i=0;i<=n;i++) query[i].clear();
    for (int i=L[id]+1;i<=R[id];i++) query[a[i]].pb(mp(i-1,pre[i]));
    spe[id].pb(0);
    int sl=0,mn=mxid[0];
    for (int i=L[id];i<=R[id];i++) ps[i][0]=mn;
    for (pii x : query[0])
        for (int i=L[id];i<=x.fi;i++) ps[i][0]=min(ps[i][0],x.se);
    vt[id][0]=R[id];
    while (vt[id][0]>L[id] && ps[vt[id][0]][0]==ps[vt[id][0]-1][0]) vt[id][0]--;
    for (int i=1;i<=n;i++)
    {
        mn=min(mn,mxid[i]);
        if (query[i].empty() && (vt[id][sl]==L[id] || ps[vt[id][sl]-1][sl]<=mn)) continue;
        sl++;
        spe[id].pb(i);
        for (int j=L[id];j<=R[id];j++) ps[j][sl]=min(ps[j][sl-1],mn);
        for (pii x : query[i])
            for (int i=L[id];i<=x.fi;i++) ps[i][sl]=min(ps[i][sl],x.se);
        vt[id][sl]=R[id];
        while (vt[id][sl]>L[id] && ps[vt[id][sl]][sl]==ps[vt[id][sl]-1][sl]) vt[id][sl]--;
    }
    for (int i=L[id]+1;i<=R[id];i++)
        for (int j=0;j<=sl;j++) ps[i][j]+=ps[i-1][j];
    int j=0;
    mn=inf;
    for (int i=0;i<=n;i++)
    {
        mn=min(mn,mxid[i]);
        if (j+1<(int)spe[id].size() && spe[id][j+1]==i) j++;
        val[id][i]=ps[R[id]][j];
        int tmp;
        if (R[id]>L[id]) tmp=ps[R[id]][j]-ps[R[id]-1][j];
        else tmp=val[id][i];
        if (tmp>mn) val[id][i]-=(tmp-mn)*(R[id]-vt[id][j]+1);
    }
}

int get_in_block(int l,int r,int k)
{
    int bl=belong[l];
    int id=upper_bound(all(spe[bl]),k)-spe[bl].begin()-1;
    int u=vt[bl][id];
    int bonus=(val[bl][k]-val[bl][spe[bl][id]])/(R[bl]-u+1);
    int res=ps[r][id];
    if (l!=L[bl]) res-=ps[l-1][id];
    if (max(u,l)<=r) res+=(r-max(u,l)+1)*bonus;
    return res;
}

ll get_range(int l,int r,int k)
{
    if (belong[l]==belong[r]) return get_in_block(l,r,k);
    int bl=belong[l],br=belong[r];
    ll res=get_in_block(l,R[bl],k)+get_in_block(L[br],r,k);
    for (int i=bl+1;i<br;i++) res+=val[i][k];
    return res;
}

ll getv(int u,int v,int k)
{
    int l=u,r=v,st=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (get_in_block(mid,mid,k)>=u) st=mid,r=mid-1;
        else l=mid+1;
    }
    if (st==-1) return 0;
    return get_range(st,v,k)-(ll)(u-1)*(v-st+1);
}

ll get(int u,int v,int k,int t)
{
    if (k<0) return (ll)(v-u+2)*(v-u+1)/2;
    if (v<=tim) return getv(u,v,k);
    ll res=0;
    if (u<=tim) res+=getv(u,tim,k);
    int mn=seg.get(1,0,n,0,k);
    for (int i=t;i>tim;i--)
    {
        if (i<=v) res+=max(0,mn-u+1);
        if (a[i]<=k) mn=min(mn,pre[i]);
    }
    return res;
}

void add(int id,int x)
{
    a[id]=x;
    pre[id]=mxid[x];
    mxid[x]=id;
    seg.update(1,0,n,x,id);
    if (id%siz==0)
    {
        tim=id;
        build(belong[id]);
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=(n-1)/siz+1;i++) L[i]=i*siz-siz+1,R[i]=min(n,i*siz);
    for (int i=1;i<=n;i++) belong[i]=(i-1)/siz+1;
    ll lans=0;
    for (int i=1;i<=n;i++)
    {
        ll x,l,r,k;
        cin>>x>>l>>r>>k;
        x=(x+lans)%(n+1);
        l=(l+lans)%i+1;
        r=(r+lans)%i+1;
        if (l>r) swap(l,r);
        k=(k+lans)%(n+1);
        add(i,x);
        lans=get(l,r,k-1,i)-get(l,r,k,i);
        cout<<lans<<"\n";
    }
    return 0;
}