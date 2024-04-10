#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e6+10,mod=1e9+7,inf=1e18;
ll n,a[maxn],f[maxn],vt[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vt[1]=1;
    if (a[2]!=a[1]) vt[2]=1; else vt[2]=2;
    for (int i=3;i<=n;i++)
        if ((a[i]>a[i-1] && a[i-1]>a[i-2]) || (a[i]<a[i-1] && a[i-1]<a[i-2])) vt[i]=vt[i-1];
        else if (a[i]!=a[i-1]) vt[i]=i-1; else vt[i]=i;
    f[2]=abs(a[1]-a[2]);
    for (int i=3;i<=n;i++)
        if (i==vt[i]) f[i]=f[i-1];
        else f[i]=max(f[vt[i]]+abs(a[i]-a[vt[i]+1]),f[vt[i]-1]+abs(a[i]-a[vt[i]]));
    cout<<f[n];
    return 0;
}