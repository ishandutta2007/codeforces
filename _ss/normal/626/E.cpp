#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+5;
ld a[maxn],pref[maxn],suff[maxn];
ll n;

void read()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}

ld ans(ll st,ll x)
{
    if (!st) return ans(st+1,x);
    if (x>=(n-x+st+1)) return ans(st+1,x);
    return ((pref[x]-pref[st-1]+suff[n-x+st+1])/(2*(x-st+1)-1)-a[x]);
}

ll bs(ll st)
{
    ll l,r=st-1,mid=(l+r)/2;
    l=max((ll)(1),2*st-n);
    if (l>r) return st;
    ld kq,kq0,kq1;
    while (l<=r)
    {
        mid=(l+r)/2;
        kq=ans(mid,st);
        kq0=ans(mid-1,st);
        kq1=ans(mid+1,st);
        if (kq>=kq0 && kq>=kq1) return mid;
        if (kq>=kq0 && kq<=kq1) l=mid+1;
        else r=mid-1;
    }
    return mid;
}

void process()
{
    pref[1]=a[1];
    for (int i=2;i<=n;i++) pref[i]=pref[i-1]+a[i];
    suff[n]=a[n];
    for (int i=n-1;i;i--) suff[i]=suff[i+1]+a[i];
    ld maxv=-1,kq;
    pii mark;
    mark={1,1};
    ll k=1;
    for (int i=2;i<=n;i++)
    {
        ll t=bs(i);
        kq=ans(t,i);
        if (kq>maxv)
        {
            maxv=kq;
            mark.fi=t;
            mark.se=i;
            k=(i-t)*2+1;
        }
    }
    //cout<<maxv<<endl;
    cout<<k<<endl;
    for (int i=mark.fi;i<=mark.se;i++) cout<<(ll)(a[i])<<" ";
    k-=mark.se-mark.fi+1;
    for (int i=n-k+1;i<=n;i++) cout<<(ll)(a[i])<<" ";
}
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}