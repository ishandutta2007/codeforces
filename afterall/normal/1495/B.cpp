#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
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
const int N=2e5+100;
ll a[N];
ll dp[N][2];
int32_t main(){
    sync;
    ll n;
    cin >> n ;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector <pii> b;
    for (int i=1;i<=n;i++) b.pb({a[i],i});
    sort(b.begin(),b.end());
    for (auto U : b){
        ll u=U.S;
        dp[u][0]=dp[u-1][0]+1;
        dp[u][1]=dp[u+1][1]+1;
    }
    ll mx0=0,mx1=0;
    for (int i=1;i<=n;i++){
        mx0=max(mx0,dp[i][0]);
        mx1=max(mx1,dp[i][1]);
    }
    if (mx0!=mx1) kill(0);
    ll t=0;
    for (int i=1;i<=n;i++){
        if (mx0==dp[i][0] || mx1==dp[i][1]) t++;
    }
    if (t>1) kill(0);
    if (mx0%2==0) kill(0);
    kill(1);


}