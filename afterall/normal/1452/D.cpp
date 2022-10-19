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
ll mod=998244353 ;
ll power(ll n,ll k){
    if (k==0){
        return 1;
    }
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll dp[N],p1=0,p2=0;
int Main(){
    ll n;
    cin >> n;
    ll z=power(2,mod-2);
    dp[1]=z;
    p1=z;
    p2=z;
    for (int i=2;i<=n;i++){
        p1*=z;
        p2*=z;
        p1%=mod;
        p2%=mod;
        if (i%2==0){
            dp[i]=p1;
            p2+=p1;
            p2%=mod;
        }
        else{
            dp[i]=p2;
            p1+=p2;
            p1%=mod;
        }
       // cout << p1 << " " << p2 << endl;
    }
    cout << dp[n] << endl;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    //cin >> t;
    while(t--) Main();
}