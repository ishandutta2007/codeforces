#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=2e5+1,msiz=2,mod=1e9+7,inf=1e18;

struct ds
{
    ll id,v,t;
};

ds a[maxn];
ll n,T;

bool cmp(ds obj1,ds obj2) {return (obj1.t<obj2.t);}

bool check(int x)
{
    ll res=0,d=0;
    for (int i=1;i<=n && d<x;i++)
        if (a[i].v>=x) res+=a[i].t,d++;
    return (d==x && res<=T);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>T;
    for (int i=1;i<=n;i++) cin>>a[i].v>>a[i].t,a[i].id=i;
    sort(a+1,a+n+1,cmp);
    int l=0,r=n,mid,ans=0;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<endl<<ans<<endl;
    int d=0;
    for (int i=1;i<=n && d<ans;i++)
        if (a[i].v>=ans) cout<<a[i].id<<" ",d++;
    return 0;
}