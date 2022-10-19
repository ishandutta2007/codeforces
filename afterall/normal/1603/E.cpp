#include <bits/stdc++.h>
#include <iostream>

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
const int N=210;
ll mod;
ll dp[N][N][N];
ll pd[N][N][N];
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
int32_t main(){
    sync;
    ll n;
    cin >> n >> mod;
    fac[0]=fm[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }

    ll ans=0;
    for (int a0=n+1;a0>max((ll)0,n-18);a0--){
        /// fix adad aval
        memset(dp,0,sizeof dp);
        memset(pd,0,sizeof pd);
        for (int i=1;i<=1;i++){
            if (i*a0<=a0*a0) {
                dp[0][0][0]+=fm[i];
                pd[i][0][0]+=fm[i];
                dp[0][0][0]%=mod;
                pd[i][0][0]%=mod;
            }
        }
        
        for (int i=2;i<=n;i++){
            for (int j=1;j<=n+1-a0;j++){
                for (int t=1;t<=min((n+1)/j,i-1);t++){
                    for (int jam=j*t;jam<=n+1;jam++){
                        dp[j][jam][t]=0;
                    }}}
            if (i*a0<=a0*a0) {
                dp[0][0][0]+=fm[i];
                pd[i][0][0]+=fm[i];
                dp[0][0][0]%=mod;
                pd[i][0][0]%=mod;
            }
            for (int j=1;j<=n+1-a0;j++){
                for (int t=1;t<=min((n+1)/j,i-1);t++){
                    for (int jam=j*t;jam<=n+1;jam++){
                        /// t tayii ke ezafe mishan barabar bashan
                        if (jam>=t && j>1){
                            dp[j][jam][t]+=dp[j-1][jam-t][t];
                            if (dp[j][jam][t]>=mod) dp[j][jam][t]-=mod;
                            
                        }
                        if (jam>=t*j && t<i) {
                            dp[j][jam][t]+=pd[i-t][j-1][jam-t*j]*fm[t]%mod;
                            if (dp[j][jam][t]>=mod) dp[j][jam][t]-=mod;
                            
                        }
                        if (a0*(a0+j)>=a0*i+jam){
                            pd[i][j][jam]+=dp[j][jam][t];
                            if (pd[i][j][jam]>=mod) pd[i][j][jam]-=mod;
                        }
                    }
                }
            }
            
        }
        for (int i=0;i<=n+1-a0;i++){
            for (int j=0;j<=n+1;j++){
                ans+=pd[n][i][j]*fac[n]%mod;
                ans%=mod;
            }
        }
      //  cout << a0 << " " << ans << endl;

    }
    cout << ans%mod << endl;;

}