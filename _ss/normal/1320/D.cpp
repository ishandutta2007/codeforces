#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=4e5+10,base=73,mod=1e9+9;
int ps1[N],n,near_l[N],near_r[N],v[N],vt[N],m;
ll a[N],h[N],powb[N];
string s;

void read()
{
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;i++)
    {
        int val=s[i-1]-'0';
        ps1[i]=ps1[i-1]+val;
        v[i]=val;
    }
}

void build()
{
    m=1;
    int cnt=0;
    for (int i=1;i<=n+1;i++)
        if (v[i]) cnt++;
        else
        {
            if (cnt&1) vt[m]=i-1,a[m++]=2;
            cnt=0;
            vt[m]=i;
            a[m++]=1;
        }
    m--;
    for (int i=1;i<=m;i++) h[i]=(h[i-1]*base+a[i])%mod;
    powb[0]=1;
    for (int i=1;i<=m;i++) powb[i]=powb[i-1]*base%mod;
    int t=0;
    for (int i=1;i<=n;i++)
    {
        if (v[i]==0) t=i;
        near_l[i]=t;
    }
    t=n+1;
    for (int i=n;i;i--)
    {
        if (v[i]==0) t=i;
        near_r[i]=t;
    }
}

ll get_hash(int l,int r)
{
    return (h[r]-h[l-1]*powb[r-l+1]+mod*mod)%mod;
}

pii get(int l,int r)
{
    int u=near_r[l],v=near_l[r];
    if (u>v) return mp(0,0);
    pii res=mp(0,0);
    if ((u-l)&1) res.fi+=10;
    if ((r-v)&1) res.fi+=1;
    u=lower_bound(vt+1,vt+m+1,u)-vt;
    v=lower_bound(vt+1,vt+m+1,v)-vt;
    res.se=get_hash(u,v);
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    read();
    build();
    cin>>q;
    for (int i=1,l1,l2,len;i<=q;i++)
    {
        cin>>l1>>l2>>len;
        int l=l1,r=l1+len-1,u=l2,v=l2+len-1;
        if ((ps1[r]-ps1[l-1])==(ps1[v]-ps1[u-1]) && get(l,r)==get(u,v)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}