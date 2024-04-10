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
const int N=1e6+100;
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
ll fac[N];
ll fm[N];
ll ent(ll k,ll n){
    if (k<0 || k>n) return 0;
    if (k==0 || k==n) return 1;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}

ll p2[N];
void Main(){
    ll n,m,k;
    cin >> n >> m >> k;
   // m=n-m;
    if (n==m){
        cout << n*k%mod << endl;
        return ;
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=(k*i)%mod*ent(m-i,n-i-1)%mod*p2[n-i]%mod;
      //  cout <<power(2,n-i) << " " << ent(m,n-i) << endl;
        ans%=mod;
    }
    cout << ans << endl;
    //cout << dp[n][m] << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    fac[0]=1;
    fm[0]=1;
    for (int i=0;i<N;i++){
        p2[i]=power(power(2,i),mod-2);
    }
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    while(t--) Main();
}