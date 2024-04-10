#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=4e5+100;
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
ll fac[N],fm[N];
ll ent(ll k,ll n){
    if (k<0 || k>n) return 0;
    if (k==0 || k==n) return 1;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
void Main(){
    fac[0]=1;
    fm[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    ll n;
    cin >> n;
    ll ans=0;
    ll z;
    for (int i=1;i<=n+1;i++){
        ll x;
        cin >> x;
       // cout << ent(x-1,x-1+i) << " " << x-1  << endl;
        ans+=ent(x-1,x+i-1);
        z=x;
    }
    cout << ans%mod << endl;

}
int32_t main(){
    sync;
    ll t=1;
    //cin >> t;
    while(t--){
        Main();
    }
}