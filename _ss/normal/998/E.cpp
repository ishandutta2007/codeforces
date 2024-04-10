#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e6+1,mod=998244353;
ll inverse[maxn],factor[maxn],ifactor[maxn],n;

ll product(ll t1,ll t2)
{
    return (t1*t2)%mod;
}

ll modpow(ll a,ll h)
{
    ll ans=1;
    for (;h;h/=2)
    {
        if (h&1) ans=product(ans,a);
        a=product(a,a);
    }
    return ans;
}

void build()
{
    ll t=max(n,(ll)(3));
    factor[0]=1;
    for (int i=1;i<=t;i++) factor[i]=product(factor[i-1],i);
    inverse[1]=1;
    for (int i=2;i<=t;i++) inverse[i]=mod-product(mod/i,inverse[mod%i]);
    ifactor[0]=1;
    for (int i=1;i<=t;i++) ifactor[i]=product(ifactor[i-1],inverse[i]);
}

ll C(ll t1,ll t2) {return product(factor[t2],product(ifactor[t1],ifactor[t2-t1]));}

int main()
{
    cin>>n;
    build();
    ll x=1,t=modpow(3,n*n);
    for (int i=1;i<n;i++) x=product(x,inverse[3]);
    ll m=mod,tmp=product(t,1-modpow(1-x+m,n)+m)*2,t2=modpow(inverse[3],n),t3=1;
    tmp%=mod;
    for (ll k=1;k<=n;k++)
    {
        t3=product(t3,t2);
        ll tmp2=product(product(C(k,n),(m+1-modpow(m+1-x,n))),product(t,t3));
        if (k&1) tmp=(tmp-product(3,tmp2)+mod)%mod;
        else tmp=(tmp+product(tmp2,3))%mod;
        x=product(x,3);
    }
    cout<<tmp;
    return 0;
}