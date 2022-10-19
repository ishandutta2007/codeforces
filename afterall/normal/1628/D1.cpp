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
const int N=2e3+100;
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
ll dp[N][N];
void Main(){
    ll n,m,k;
    cin >> n >> m >> k;
    m=n-m;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=n+1;j++){
            dp[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        dp[i][0]=k*i%mod;
    }
    ll p2=power(2,mod-2);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=min(i-1,m);j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])*p2%mod;
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][m] << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}