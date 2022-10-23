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
const ll N=2e5+10,mod=998244353,inf=1e18;

ll product(ll obj1, ll obj2)
{
    return (obj1*obj2)%mod;
}

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=product(res,x);
        x=product(x,x);
    }
    return res;
}

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

struct segment_tree
{
    pii it[N*4];

    pii combine(pii t1,pii t2)
    {
        t1.fi=t1.fi*t2.fi%mod;
        t1.se=(t1.se*t2.fi+t2.se)%mod;
        return t1;
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

    pii get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return mp(1,0);
        if (u<=l && r<=v) return it[id];
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }

};

ll n,q,p[N],mark[N];
pii a[N];
segment_tree seg;
set<int> st;
int main()
{
//    freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++) a[i].fi=(1+(100-p[i])*inverse(p[i]))%mod,a[i].se=100*inverse(p[i])%mod;
    seg.build(a,1,1,n);
    st.insert(1);
    st.insert(n+1);
    ll res=seg.it[1].se;
    for (int i=1,x;i<=q;i++)
    {
        cin>>x;
        if (!mark[x])
        {
            auto it=st.lower_bound(x);
            int v=*it;
            it--;
            int u=*it;
            pii tmp=seg.get(1,1,n,u,v-1);
            res=(res-tmp.se+mod)%mod;
            tmp=seg.get(1,1,n,u,x-1);
            res=(res+tmp.se)%mod;
            tmp=seg.get(1,1,n,x,v-1);
            res=(res+tmp.se)%mod;
            st.insert(x);
        }
        else
        {
            auto it=st.upper_bound(x);
            int v=*it;
            it=st.lower_bound(x);
            it--;
            int u=*it;
            pii tmp=seg.get(1,1,n,u,v-1);
            res=(res+tmp.se)%mod;
            tmp=seg.get(1,1,n,u,x-1);
            res=(res-tmp.se+mod)%mod;
            tmp=seg.get(1,1,n,x,v-1);
            res=(res-tmp.se+mod)%mod;
            st.erase(x);
        }
        mark[x]^=1;
        cout<<res<<"\n";
    }
    return 0;
}