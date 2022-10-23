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
const ll maxn=3e5+10,mod=1e9+7,inf=1e18;
ll n,f[maxn],a[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll p=2,res=0;
    for (int i=2;i<=n;i++)
    {
        f[i]=(f[i-1]*2+(p-1)*(a[i]-a[i-1]))%mod;
        p=(p*2)%mod;
        res=(res+f[i])%mod;
    }
    cout<<res;
    return 0;
}