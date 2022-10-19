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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100;
ll dp[N][3];
ll a[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=0;
        dp[i][2]=0;
        cin >> a[i];
    }
    ll x;
    cin >> x;
    for (int i=1;i<=n;i++){
        a[i]-=x;
    }
    dp[1][1]=1;
    a[0]=-1e9;
    for (int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1]=dp[i-1][0]+1;
        if (a[i]+a[i-1]>=0){
            dp[i][2]=dp[i-2][0]+2;
            if (a[i]+a[i-1]+a[i-2]>=0 && a[i-1]+a[i-2]>=0){
                dp[i][2]=max(dp[i][2],dp[i-1][2]+1);
            }
        }
    }
    kill(max(dp[n][0],max(dp[n][1],dp[n][2])))
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}