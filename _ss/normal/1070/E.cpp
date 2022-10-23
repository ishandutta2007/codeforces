#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;

ll n,m,t,p[N];

struct segment_tree
{
    pii it[N*4];

    pii combine(pii t1,pii t2)
    {
        return mp(t1.fi+t2.fi,t1.se+t2.se);
    }

    void build(int id,int l,int r)
    {
        if (l==r)
        {
            it[id]=mp(0,0);
            return;
        }
        int mid=(l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    void update(int id,int l,int r,int v,pii x)
    {
        if (l==r)
        {
            it[id]=x;
            return;
        }
        int mid=(l+r)>>1;
        if (v<=mid) update(id*2,l,mid,v,x);
        else update(id*2+1,mid+1,r,v,x);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    ll lw(int id,int l,int r,int x)
    {
        if (l==r) return it[id].fi;
        int mid=(l+r)>>1;
        if (it[id*2].se>=x) return lw(id*2,l,mid,x);
        else return it[id*2].fi+lw(id*2+1,mid+1,r,x-it[id*2].se);
    }
};

void read()
{
    cin>>n>>m>>t;
    for (int i=1;i<=n;i++) cin>>p[i];
}

segment_tree seg;
pii tp[N];

ll val(int x)
{
    ll tmp=seg.lw(1,1,n,x);
    if ((x-1)/m>0) tmp+=seg.lw(1,1,n,(x-1)/m*m);
    return tmp;
}

int get(int sl)
{
    int l=1,r=sl,ans=0;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (val(mid)<=t) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}

void process()
{
    seg.build(1,1,n);
    for (int i=1;i<=n;i++) tp[i]=mp(p[i],i);
    sort(tp+1,tp+n+1);
    tp[n+1].fi=0;
    pii res=mp(0,1);
    for (int i=1;i<=n;i++)
    {
        if (tp[i].fi>t) break;
        seg.update(1,1,n,tp[i].se,mp(tp[i].fi,1));
        if (tp[i].fi!=tp[i+1].fi) res=max(res,mp((ll)get(i),tp[i].fi));
    }
    cout<<res.fi<<" "<<res.se<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}