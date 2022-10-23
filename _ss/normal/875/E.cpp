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
const ll maxn=1e5+10,mod=1e9+7,inf=1e9+1;
int it[maxn*4],lazy[maxn*4],s1,s2,a[maxn],n;

void build(int id,int l,int r)
{
    if (l==r)
    {
        it[id]=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2,mid+1,r);
    it[id]=max(it[id*2],it[id*2+1]);
}

void down(int id)
{
    it[id*2]=0;
    lazy[id*2]=1;
    it[id*2+1]=0;
    lazy[id*2+1]=1;
    lazy[id]=0;
}

void turn_on(int id,int l,int r,int v)
{
    if (l==r)
    {
        it[id]=1;
        return;
    }
    int mid=(l+r)/2;
    if (lazy[id]) down(id);
    if (v<=mid) turn_on(id*2,l,mid,v);
    else turn_on(id*2+1,mid+1,r,v);
    it[id]=max(it[id*2],it[id*2+1]);
}

void turn_off(int id,int l,int r,int u,int v)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        it[id]=0;
        lazy[id]=1;
        return;
    }
    if (lazy[id]) return;
    int mid=(l+r)/2;
    turn_off(id*2,l,mid,u,v);
    turn_off(id*2+1,mid+1,r,u,v);
    it[id]=max(it[id*2],it[id*2+1]);
}

vector<int> loc;

bool check(int x)
{
    build(1,1,n+2);
    turn_off(1,1,n+2,1,n+2);
    int vt=lower_bound(all(loc),s2)-loc.begin()+1;
    turn_on(1,1,n+2,vt);
    for (int i=1;i<=n;i++)
    {
        if (!it[1]) return false;
        if (abs(a[i]-a[i-1])<=x)
        {
            vt=lower_bound(all(loc),a[i-1])-loc.begin()+1;
            turn_on(1,1,n+2,vt);
        }
        vt=upper_bound(all(loc),a[i]+x)-loc.begin()+1;
        if (vt<=n+2) turn_off(1,1,n+2,vt,n+2);
        vt=lower_bound(all(loc),a[i]-x)-loc.begin();
        if (vt) turn_off(1,1,n+2,1,vt);
    }
    return (it[1]==1);
}

void read()
{
    cin>>n>>s1>>s2;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void process()
{
    loc.pb(s1);
    loc.pb(s2);
    for (int i=1;i<=n;i++) loc.pb(a[i]);
    sort(all(loc));
    a[0]=s1;
    ll l=abs(s1-s2),r=inf,mid,ans=inf;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
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