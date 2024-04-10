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
const int N=500;
ll dp[N][N];
ll a[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    memset(dp,31,sizeof dp);
    dp[0][0]=0;
    for (int i=0;i<N;i++) dp[i][0]=0;
    for (int i=1;i<N;i++){
        for (int j=1;j<=min(i,n);j++){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(i-a[j]));
        }
    }
    ll ans=1e9;
    for (int i=n;i<N;i++) ans=min(ans,dp[i][n]);
    cout << ans << endl;
}
int32_t main(){
    ll t;
    cin >> t;
    while(t--){
        Main();
    }

}