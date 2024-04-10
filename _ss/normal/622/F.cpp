#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e6+10,mod=1e9+7,inf=1e18;
ll n,k,ifact[N],inverse[N],res[N],ps1[N],ps2[N];

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

void build()
{
    inverse[1]=ifact[0]=ifact[1]=1;
    for (int i=2;i<=k+2;i++)
    {
        inverse[i]=mod-mod/i*inverse[mod%i]%mod;
        ifact[i]=(ifact[i-1]*inverse[i])%mod;
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=k+2;i++) res[i]=(res[i-1]+modpow(i,k))%mod;
    if (n<=k+2)
    {
        cout<<res[n];
        return 0;
    }
    build();
    ps1[0]=ps2[k+3]=1;
    for (int i=1;i<=k+2;i++) ps1[i]=ps1[i-1]*(n-i)%mod;
    for (int i=k+2;i;i--) ps2[i]=ps2[i+1]*(n-i)%mod;
    ll ans=0;
    for (int i=1;i<=k+2;i++)
    {
        ll tmp=res[i]*ps1[i-1]%mod*ps2[i+1]%mod*ifact[i-1]%mod*ifact[k+2-i]%mod;
        if ((k+2-i)&1) ans=(ans-tmp+mod)%mod;
        else ans=(ans+tmp)%mod;
    }
    cout<<ans;
    return 0;
}