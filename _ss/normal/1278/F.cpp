#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=5e3+10,mod=998244353,inf=1e18;
ll dp[N][N],n,m,k,val[N],res[N],inv[N],ps1[N],ps2[N],ifact[N];

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

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

void build()
{
    inv[1]=ifact[0]=ifact[1]=1;
    for (int i=2;i<=k+1;i++)
    {
        inv[i]=mod-mod/i*inv[mod%i]%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    ll im=inverse(m);
    dp[0][0]=1;
    for (int i=1;i<=k+1;i++)
    {
        dp[i][0]=dp[i-1][0]*(m-1)%mod*im%mod;
        for (int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j]*(m-1)%mod*im%mod+dp[i-1][j-1]*im%mod)%mod;
    }
    for (int i=1;i<=k+1;i++) val[i]=modpow(i,k);
    for (int i=1;i<=k+1;i++)
        for (int j=1;j<=i;j++) res[i]=(res[i]+val[j]*dp[i][j])%mod;
    if (n<=k+1)
    {
        cout<<res[n];
        return 0;
    }
    build();
    ps1[0]=ps2[k+2]=1;
    for (int i=1;i<=k+1;i++) ps1[i]=ps1[i-1]*(n-i)%mod;
    for (int i=k+1;i;i--) ps2[i]=ps2[i+1]*(n-i)%mod;
    ll ans=0;
    for (int i=1;i<=k+1;i++)
    {
        ll tmp=res[i]*ps1[i-1]%mod*ps2[i+1]%mod*ifact[i-1]%mod*ifact[k+1-i]%mod;
        if ((k+1-i)&1) ans=(ans-tmp+mod)%mod;
        else ans=(ans+tmp)%mod;
    }
    cout<<ans;
    return 0;
}