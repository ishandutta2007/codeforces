#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

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
    if(n<k) cout << "0\n";
    else
    {
        vector<ll> f(n+1,1);
        for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
        vector<ll> finv(n+1,1);
        finv[n]=fpow(f[n],mod-2);
        for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
        auto c=[&](ll a,ll b)->ll
        {
            if(a<b) return 0;
            ll res=f[a];
            res=(res*finv[b])%mod;
            res=(res*finv[a-b])%mod;
            return res;
        };
        ll res=0;
        for(ll i=1;i<=n;i++) res=(res+c(n/i-1,k-1))%mod;
        cout << res << "\n";
    }
    return 0;
}