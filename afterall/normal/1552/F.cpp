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
const int N=2e5+100;
ll mod=998244353;
ll x[N];
ll y[N];
ll s[N];
ll dp[N];
ll par[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> x[i] >> y[i] >> s[i];
    }
    for (int i=1;i<=n;i++){
        dp[i]=x[i]-y[i];
      //  dp[i]*=2;
        ll z=upper_bound(x+1,x+n+1,y[i])-x;
        dp[i]+=par[i-1]-par[z-1];
        dp[i]+=mod;
        dp[i]%=mod;
        par[i]=par[i-1]+dp[i];
        par[i]%=mod;
      //  cout << dp[i] << endl;
    }
    ll ans=x[n]+1;
    for (int i=1;i<=n;i++){
        if (s[i]) ans+=dp[i];
        ans%=mod;
    }
    cout << ans << endl;
}