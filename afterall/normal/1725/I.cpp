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
const int N=2e5+100;
ll mod=998244353;
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
ll sig(ll n){
    return n*(n+1)/2;
}
ll par[N];
ll sz[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
void merg(ll u,ll v){
    u=getpar(u);
    v=getpar(v);
    par[u]=v;
    sz[v]+=sz[u];
}
int32_t main(){
    sync;
    fac[0]=fm[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    ll n;
    cin >> n ;
    ll ans=fac[2*n-2]*power(power(2,n-1),mod-2)%mod*fm[n-1]%mod;;
  //  cout << ans << endl;
    for (int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        u=getpar(u);
        v=getpar(v);
       // cout << u << " " << v << " " << sz[u] << " " << sz[v] << endl;
        ans*=sz[u]*sz[v]%mod*sz[u]%mod*sz[v]%mod;
        ans%=mod;
        merg(u,v);
    }
    cout << ans << endl;
}