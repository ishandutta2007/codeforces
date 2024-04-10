#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=2e5+10,mod=998244353,inf=1e18;

ll it[maxn*4],n;
pii lazy[maxn*4];

void build(int id,int l,int r)
{
    if (l==r)
    {
        lazy[id]=mp(1,0);
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    lazy[id]=mp(1,0);
}

void down(int id,int l,int r)
{
    ll a=lazy[id].fi,b=lazy[id].se,mid=(l+r)>>1;
    it[id*2]=(it[id*2]*a+b*(mid-l+1))%mod;
    lazy[id*2].fi=(lazy[id*2].fi*a)%mod;
    lazy[id*2].se=(lazy[id*2].se*a+b)%mod;
    it[id*2+1]=(it[id*2+1]*a+b*(r-mid))%mod;
    lazy[id*2+1].fi=(lazy[id*2+1].fi*a)%mod;
    lazy[id*2+1].se=(lazy[id*2+1].se*a+b)%mod;
    lazy[id]=mp(1,0);
}

void update(int id,int l,int r,int u,int v,int a,int b)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        it[id]=(it[id]*a+b*(r-l+1))%mod;
        lazy[id].fi=(lazy[id].fi*a)%mod;
        lazy[id].se=(lazy[id].se*a+b)%mod;
        return;
    }
    down(id,l,r);
    int mid=(l+r)>>1;
    update(id*2,l,mid,u,v,a,b);
    update(id*2+1,mid+1,r,u,v,a,b);
    it[id]=(it[id*2]+it[id*2+1])%mod;
}

ll get(int id,int l,int r,int u,int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return it[id];
    down(id,l,r);
    int mid=(l+r)>>1;
    return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v))%mod;
}

set<pii> interval[maxn];

void query1(int l,int r,int x)
{
    if (!interval[x].size())
    {
        interval[x].insert(mp(l,r));
        update(1,1,n,l,r,1,1);
        return;
    }
    pii tmp=mp(l,0);
    auto ir=interval[x].lower_bound(tmp);
    int t=l,tmpl=l;
    if (ir!=interval[x].begin())
    {
        ir--;
        tmp=*ir;
        if (tmp.se>=r)
        {
            update(1,1,n,l,r,2,0);
            return;
        }
        if (tmp.se>=l)
        {
            update(1,1,n,l,tmp.se,2,0);
            l=tmp.fi;
            interval[x].erase(ir);
            t=tmp.se+1;
        }
        ir=interval[x].lower_bound(mp(tmpl,0));
    }
    if (ir!=interval[x].end()) tmp=*ir;
    else tmp=mp(n+1,n+1);
    if (tmp.fi>r)
    {
        update(1,1,n,t,r,1,1);
        interval[x].insert(mp(l,r));
        return;
    };
    while (tmp.fi<=r)
    {
        if (t<=tmp.fi-1) update(1,1,n,t,tmp.fi-1,1,1);
        if (tmp.se>r)
        {
            update(1,1,n,tmp.fi,r,2,0);
            interval[x].erase(ir);
            r=tmp.se;
            interval[x].insert(mp(l,r));
            return;
        }
        update(1,1,n,tmp.fi,tmp.se,2,0);
        t=tmp.se+1;
        interval[x].erase(ir);
        ir=interval[x].lower_bound(mp(l,r));
        if (ir==interval[x].end())
        {
            update(1,1,n,t,r,1,1);
            break;
        }
        tmp=*ir;
    }
    if (ir!=interval[x].end() && t<=r) update(1,1,n,t,r,1,1);
    interval[x].insert(mp(l,r));
}

int main()
{
    //freopen("mm.inp","r",stdin);
    //freopen("mm.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    build(1,1,n);
    for (int i=1,t,l,r,x;i<=q;i++)
    {
        cin>>t>>l>>r;
        if (t==1)
        {
            cin>>x;
            query1(l,r,x);
        }
        else cout<<get(1,1,n,l,r)<<"\n";
    }
    return 0;
}