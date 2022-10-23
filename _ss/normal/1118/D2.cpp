#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=2e5+1;
ll a[maxn],n,m,s[maxn];

bool cmp(ll t1,ll t2)
{
    return t1>t2;
}

bool solve(ll x)
{
    ll d=1;
    while (d<=n/x && a[d*x]>(d-1)) d++;
    ll kq=s[d*x-x]-x*(d-2)*(d-1)/2;
    if (kq>=m) return true;
    for (ll i=(d-1)*x+1;i<=n;i++)
        if (a[i]>d-1) kq=kq+a[i]-d+1;
    return (kq>=m);
}
int main()
{
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for (ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    if (s[n]<m)
    {
        cout<<-1;
        return 0;
    }
    ll l=1,r=n,mid,kq;
    while (l<=r)
    {
        mid=(l+r)/2;
        bool kt=solve(mid);
        if (kt)
        {
            kq=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<kq;
    return 0;
}