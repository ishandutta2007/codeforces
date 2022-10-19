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
ll cnt[N],f[N];
ll ans[N];
ll sig[N];
int32_t main(){
    sync;

    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        ll x,t;
        cin >> x >> t;
        cnt[x]+=t;
    }
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j+=i){
            f[i]+=cnt[j];
            sig[i]+=cnt[j]*j;
            sig[i]%=mod;
        }
        if (f[i]<2) continue;
        ll z=power(2,f[i]-2)*((f[i]-1)%mod)%mod;
        for (int j=i;j<N;j+=i){
            ans[i]+=z*j%mod*j%mod*cnt[j]%mod;
            ans[i]%=mod;
        }
     //   cout << i << " " << ans[i] << endl;
        if (f[i]<3) z=1;
        else
        z=power(2,f[i]-3)*((f[i]-2)%mod)%mod+power(2,f[i]-2);
        z%=mod;
        for (int j=i;j<N;j+=i){
            ans[i]+=cnt[j]*j%mod*(sig[i]-j+mod)%mod*z%mod;
            ans[i]%=mod;
        }
    }
    for (int i=N-1;i;i--){
        for (int j=i*2;j<N;j+=i){
            ans[i]-=ans[j];
            ans[i]+=mod;
            ans[i]%=mod;
        }
    }
    cout << ans[1] << endl;
}