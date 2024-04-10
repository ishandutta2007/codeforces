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
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> dp(n+1,0);
    dp[0]=1;
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto c=[&](int d,int e)->ll
    {
        ll res=f[d];
        res=(res*finv[e])%mod;
        res=(res*finv[d-e])%mod;
        return res;
    };
    ll sum=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0) for(int j=i+a[i];j<=n;j++) dp[j]=(dp[j]+sum*c(j-i-1,a[i]-1))%mod;
        sum=(sum+dp[i])%mod;
    }
    cout << (sum-1+mod)%mod << "\n";
    return 0;
}