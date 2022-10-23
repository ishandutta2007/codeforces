#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
const ll base=37,mod=1e9+9;
int n,m,pre[N],suf[N*2];
ll a[N],b[N],s[N],powb[N];
string STR;

struct segment_tree
{
    ll it[N*4],lazy[N*4];

    ll combine(ll t1,ll t2)
    {
        return t1+t2;
    }

    void down(int id,int l,int r)
    {
        ll tmp=lazy[id],mid=(l+r)>>1;
        it[id*2]+=tmp*(mid-l+1);
        it[id*2+1]+=tmp*(r-mid);
        lazy[id*2]+=tmp;
        lazy[id*2+1]+=tmp;
        lazy[id]=0;
    }

    void update_range(int id,int l,int r,int u,int v,int x)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            it[id]+=x*(r-l+1);
            lazy[id]+=x;
            return;
        }
        down(id,l,r);
        int mid=(l+r)>>1;
        update_range(id*2,l,mid,u,v,x);
        update_range(id*2+1,mid+1,r,u,v,x);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    ll get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return it[id];
        down(id,l,r);
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} seg;

void read()
{
    cin>>n>>m;
    cin>>STR;
    for (int i=1;i<=n;i++) a[i]=(a[i-1]*base+STR[i-1]-'a'+1)%mod;
    cin>>STR;
    for (int i=1;i<=n;i++) b[i]=(b[i-1]*base+STR[i-1]-'a'+1)%mod;
    cin>>STR;
    for (int i=1;i<=m;i++) s[i]=(s[i-1]*base+STR[i-1]-'a'+1)%mod;
    powb[0]=1;
    for (int i=1;i<=n*2;i++) powb[i]=powb[i-1]*base%mod;
}

ll get_hash(ll h[],int l,int r)
{
    return (h[r]-h[l-1]*powb[r-l+1]+mod*mod)%mod;
}

void process()
{
    for (int i=1;i<=n;i++)
    {
        int l=0,r=n-i+1;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (get_hash(a,i,i+mid-1)==get_hash(s,1,mid)) pre[i]=mid,l=mid+1;
            else r=mid-1;
        }
    }
    for (int i=1;i<=n;i++)
    {
        int l=0,r=i;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (get_hash(b,i-mid+1,i)==get_hash(s,m-mid+1,m)) suf[i]=mid,l=mid+1;
            else r=mid-1;
        }
    }
    ll res=0;
    for (int i=1;i<=m-2;i++)
        if (suf[i]>0) seg.update_range(1,1,m,m-suf[i],m-1,1);
    for (int i=1;i<=n;i++)
    {
        if (suf[i+m-2]>0) seg.update_range(1,1,m,m-suf[i+m-2],m-1,1);
        if (pre[i]>0) res+=seg.get(1,1,m,1,pre[i]);
        seg.update_range(1,1,m,m-suf[i],m-1,-1);
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