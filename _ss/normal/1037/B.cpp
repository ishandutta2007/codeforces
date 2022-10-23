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
ll a[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,s,res=0;
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (a[n/2+1]<s) {
    for (int i=n/2+1;i<=n;i++)
        if (a[i]<s) res+=s-a[i];}
    else{ for (int i=1;i<=n/2+1;i++)
        if (a[i]>s) res+=a[i]-s;}
    cout<<res;
    return 0;
}