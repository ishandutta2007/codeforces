#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100;
ll fac[N];
ll fm[N];
ll mod=998244353;
ll dp[N];
ll pd[N];
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
    if (k<0 || k>n) return 0;
    if (k==0 || k==n) return 1;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
void Main(){
    
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll t2=n-i;
        if (i<t2) continue;
        ans+=ent(t2,i)*dp[i-t2]%mod*pd[t2]%mod;
      //  if (n!=50) cout << i << " " << T[n][i] << " " << dp[i-t2] << " " << pd[t2] << " " << t2 << endl;
        ans%=mod;
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    fac[0]=1;

    for (int i=1;i<N;i++) {
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    dp[0]=1;
    dp[1]=1;
    pd[0]=1;
    for (int i=2;i<N;i++){
        dp[i]=dp[i-2]*(i-1)+dp[i-1];
        dp[i]%=mod;
        pd[i]=pd[i-2]*(i-1)*2;
        pd[i]%=mod;
    }

    ll t=1;
    cin >> t;
    while(t--) Main();
}