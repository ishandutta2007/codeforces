#include <bits/stdc++.h>
/// this time?
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll mod=1e9+7;
ll fac[N],fm[N],dp[N];
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll ent(ll k,ll n){
    if (k==0 || k==n) return 1;
    if (k<0 || k>n) return 0;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
int32_t main(){
    sync;
    fac[0]=1;
    fm[0]=1;
    for (int i=1;i<N;i++) {
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    ll t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof dp);
        ll n,k;
        cin >> n >> k;
        for (int i=1;i<=n;i++){
            ll z=n-(i-1)*(k-1);
            if (z<i) continue;
            dp[i]=ent(i,z);
            dp[i]*=fac[i]*fac[n-i]%mod;
            dp[i]%=mod;
            dp[i]*=power(fac[n],mod-2);
            dp[i]%=mod;
        }
        ll ans=0;
        for (int i=1;i<=n;i++){
            dp[i]-=dp[i+1];
            dp[i]+=mod;
            dp[i]%=mod;
            ans+=dp[i]*(i+1)%mod;
        }
        cout << ans%mod << endl;

    }

}