#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=2e5+100,mod=1e9+7,inf=1e18;
pii a[maxn];
int n,it[maxn*4],m,ans[maxn],b[maxn];
vector<pii> query[maxn];

struct ds
{
    int k,pos,id;
};

bool cmp(pii t1,pii t2)
{
    if (t1.fi==t2.fi) return t1.se<t2.se;
    return t1.fi>t2.fi;
}

void add(int id,int l,int r,int vt)
{
    if (l==r)
    {
        it[id]=1;
        return;
    }
    int mid=(l+r)>>1;
    if (vt<=mid) add(id*2,l,mid,vt);
    else add(id*2+1,mid+1,r,vt);
    it[id]=it[id*2]+it[id*2+1];
}

int lower(int id,int l,int r,int val)
{
    if (l==r) return l;
    int mid=(l+r)>>1;
    if (val<=it[id*2]) return lower(id*2,l,mid,val);
    return lower(id*2+1,mid+1,r,val-it[id*2]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi,a[i].se=i,b[i]=a[i].fi;
    sort(a+1,a+n+1,cmp);
    cin>>m;
    for (int i=1,k,pos;i<=m;i++) cin>>k>>pos,query[k].pb(mp(pos,i));
    for (int i=1;i<=n;i++)
    {
        add(1,1,n,a[i].se);
        for (pii x : query[i])
        {
            int vt=lower(1,1,n,x.fi);
            ans[x.se]=b[vt];
        }
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<"\n";
    return 0;
}