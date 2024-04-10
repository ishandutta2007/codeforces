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
const ll maxn=5e3+10,mod=998244353,inf=1e18;
ll dp[maxn][maxn],n,a[maxn],inverse[maxn];

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1,x=x*x%mod)
        if (h&1) res=res*x%mod;
    return res;
}

ll inverse_mod(ll x) { return modpow(x,mod-2); }

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1,x;i<=n;i++) cin>>x,a[x]++,inverse[i]=inverse_mod(i);
    for (int i=1;i<=n;i++) dp[1][i]=(inverse[n]*a[i])%mod;
    ll res=0;
    for (int i=2;i<=n;i++)
    {
        ll tmp=0;
        for (int j=1;j<=n;j++)
        {
            res=(res+dp[i-1][j]*inverse[n-i+1]%mod*(a[j]-1))%mod;
            dp[i][j]=(tmp*a[j])%mod;
            tmp=(tmp+dp[i-1][j]*inverse[n-i+1])%mod;
        }
    }
    cout<<res;
    return 0;
}