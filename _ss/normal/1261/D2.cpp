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
const ll maxn=2e5+100,mod=998244353,inf=1e18;
ll fact[maxn],n,a[maxn];

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1,x=x*x%mod)
        if (h&1) res=res*x%mod;
    return res;
}

ll inverse(ll x) { return modpow(x,mod-2); }

ll C(ll k,ll x) { return fact[x]*inverse(fact[k]*fact[x-k]%mod)%mod; }

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>n>>k;
    fact[0]=1;
    for (int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sl=0;
    for (int i=1;i<n;i++)
        if (a[i]!=a[i+1]) sl++;
    if (a[n]!=a[1]) sl++;
    ll res=0;
    for (ll i=0;i<sl;i++)
    {
        ll t=sl-i,tmp;
        if (t&1) tmp=modpow(2,t-1);
        else tmp=(modpow(2,t)-C(t/2,t)+mod)%mod*inverse(2)%mod;
        res=(res+tmp*modpow(k-2,i)%mod*C(i,sl))%mod;
    }
    res=res*modpow(k,n-sl)%mod;
    cout<<res;
    return 0;
}