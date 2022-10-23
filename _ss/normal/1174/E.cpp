#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll mod=1e9+7,maxn=1e6+1;
ll n,a[100],factor[maxn];

ll modpow(ll x,ll h)
{
    if (h==1) return x;
    ll t=modpow(x,h/2);
    t=(t*t)%mod;
    if (h&1) t=(t*x)%mod;
    return t;
}

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

ll c(ll k,ll h)
{
    return (factor[h]*inverse(factor[h-k]))%mod;
}

int main()
{
    cin>>n;
    factor[0]=1;
    for (int i=1;i<=n;i++) factor[i]=(factor[i-1]*i)%mod;
    ll t=n,d=2;
    while (t>3) t/=2,d++;
    ll p=2,l=n-n/2;
    a[1]=factor[n-n/2];
    for (ll i=2;i<=d;i++)
    {
        a[i]=(((a[i-1]*(n/p-n/(p*2)))%mod)*c(n/p-n/(p*2)-1,n/p-n/(p*2)-1+l))%mod;
        l+=n/p-n/(p*2);
        p*=2;
    }
    a[0]=1;
    ll ans=a[d],kq,s=1;
    if (t-2)
    {
        p=p/4*3;
        l-=1;
        for (ll i=d-1;i>=2;i--)
        {
            kq=(((((s*a[i-1])%mod)*(n/(p/3)-n/p))%mod)*c(n/(p/3)-n/p-1,l-1))%mod;
            s=(((s*(n/(p/2)-n/p))%mod)*c(n/(p/2)-n/p-1,l-1))%mod;
            l-=n/(p/2)-n/p;
            ans=(ans+kq)%mod;
            p/=2;
        }
        kq=(s*factor[l])%mod;
        ans=(ans+kq)%mod;
    }
    cout<<ans;
    //cout<<endl<<(((((((((((((factor[32]*16)%mod)*c(15,47))%mod)*8)%mod)*c(7,55))%mod)*4)%mod)*c(3,59))%mod)*2*c(1,61))%mod;
    return 0;
}