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
const int N=1e6+100;
ll mod=998244353 ;
ll dp[N],par[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    dp[0]=1;
    par[0]=1;
    for (int i=1;i<=n;i++){
        dp[i]+=par[i-1];
        dp[i]%=mod;
        ll j=2*i;
        for (int k=j+j;k<=2*n;k+=j){
            dp[k/2]+=1;
            dp[k/2]%=mod;
        }
        par[i]=par[i-1]+dp[i];
        par[i]%=mod;
    }
    kill(dp[n]);
}