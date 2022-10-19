#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=410;
ll dp[N][N];
ll mod;
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
ll p2[N];
int32_t main(){
    sync;
    ll n;
    cin >> n >> mod;
    fac[0]=1;
    fm[0]=1;
    p2[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
        p2[i]=power(2,i);
    }
    for (int i=1;i<=n;i++){
        dp[1][i]=fm[i]*p2[i-1]%mod;
    }
    for (int i=2;i<=n;i++){
        for (int j=2;j<=n;j++){
            for (int k=1;k<j;k++){
                ll z=1;
                dp[i][j]+=dp[i-1][j-k-1]*fm[k]%mod*p2[k-1]%mod;
                dp[i][j]%=mod;
            }
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll z=n-i+1;
        ll w=fac[z]*dp[i][n]%mod;
       // cout << i << " " << w << endl;
        ans+=w;
        ans%=mod;
    }
    kill(ans);
}