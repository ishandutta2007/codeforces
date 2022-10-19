#include <bits/stdc++.h>
/// 500 485 462 A4
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
const int N=15,inf=(ll)1e18;
ll a[N];
ll mod=1e9+7;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll b[N][(1<<N)];
ll dp[(1<<N)];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        for (int mask=0;mask<(1<<n);mask++){
            b[i][mask]=1;
            for (int j=0;j<n;j++){
                if (mask & (1<<j)){
                    b[i][mask]*=a[i]*power(a[i]+a[j],mod-2)%mod;
                    b[i][mask]%=mod;
                }
            }
        }
    }
    ll ans=0;
    for (int mask=1;mask<(1<<n);mask++){
        dp[mask]=1;
        for (int sub=mask;sub>0;sub=(mask & (sub-1))){
            if (sub==mask) continue;
            ll z=1;
            for (int i=0;i<n;i++){
                if (sub & (1<<i)){
                    z*=b[i][mask-sub];
                    z%=mod;
                }
            }

            dp[mask]-=dp[sub]*z%mod;
            dp[mask]+=mod;
            dp[mask]%=mod;
        }
        ll z=(1<<n)-1;
        ll x=1;
        for (int i=0;i<n;i++){
            if (mask & (1<<i)){
                x*=b[i][z-mask];
                x%=mod;
            }
        }
        ll o=__builtin_popcount(mask);
        ans+=dp[mask]*x%mod*o%mod;
        ans%=mod;
      //  cout << mask << " " << dp[mask] << " " << x << endl;
    }
    cout << ans << endl;

}