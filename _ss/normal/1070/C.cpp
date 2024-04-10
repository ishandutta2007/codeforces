#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18,N2=1e6+10;

struct segment_tree
{
    pii it[N*4];

    pii combine(pii t1,pii t2)
    {
        return mp(t1.fi+t2.fi,t1.se+t2.se);
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
        if (l==r)
        {
            if (it[id].se==0) return 0;
            return it[id].fi/it[id].se*min((ll)x,it[id].se);
        }
        int mid=(l+r)>>1;
        if (it[id*2].se>=x) return lw(id*2,l,mid,x);
        else return it[id*2].fi+lw(id*2+1,mid+1,r,x-it[id*2].se);
    }
};

struct ds {ll l,r,c,p; };
struct ds2 {ll id,c,p; };
int n,k,m;
ds query[N];

void read()
{
    cin>>n>>k>>m;
    for (int i=1;i<=m;i++) cin>>query[i].l>>query[i].r>>query[i].c>>query[i].p;
}

bool cmp(ds t1,ds t2) {return t1.p<t2.p; }
segment_tree seg;
vector<ds2> on[N2],off[N2];

void process()
{
    sort(query+1,query+m+1,cmp);
    for (int i=1;i<=m;i++) on[query[i].l].pb({i,query[i].c,query[i].p}),off[query[i].r+1].pb({i,query[i].c,query[i].p});
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        for (ds2 x : on[i]) seg.update(1,1,m,x.id,mp(x.c*x.p,x.c));
        for (ds2 x : off[i]) seg.update(1,1,m,x.id,mp(0,0));
        ans+=seg.lw(1,1,m,k);
    }
    cout<<ans;
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