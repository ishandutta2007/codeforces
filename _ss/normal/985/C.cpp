#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;
ll n,k,a[maxn],l;
int main()
{
    //freopen("ss.inp","r",stdin);
    cin>>n>>k>>l;
    for (int i=1;i<=n*k;i++) scanf("%I64d",&a[i]);
    sort(a+1,a+n*k+1);
    if (a[n]-a[1]>l)
    {
        cout<<0;
        return 0;
    }
    ll t=n;
    while (t<=n*k && a[t]-a[1]<=l) t++;
    t--;
    ll vt=1,s=0;
    while (t-vt+1>=n && n)
    {
        s+=a[vt];
        vt+=k;
        n--;
    }
    for (int i=t-n+1;i<=t;i++) s+=a[i];
    cout<<s;
    return 0;
}