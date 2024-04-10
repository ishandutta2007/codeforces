#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto c=[&](int a,int b)->ll
    {
        ll res=f[a];
        res=(res*finv[b])%mod;
        res=(res*finv[a-b])%mod;
        return res;
    };
    ll res=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            ll now=c(n,i);
            now=(now*c(n,j))%mod;
            now=(now*fpow(k-1,n*i+n*j-i*j))%mod;
            now=(now*fpow(k,n*n-(n*i+n*j-i*j)))%mod;
            if((i+j)&1) res=(res-now+mod)%mod;
            else res=(res+now)%mod;
        }
    }
    cout << res << "\n";
    return 0;
}