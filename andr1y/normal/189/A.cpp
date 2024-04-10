// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll dp[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    memset(dp, 0b10111111, sizeof(dp));
    dp[0]=0;
    for(ll i = 1;i<=n;i++){
        if(i>=a) dp[i]=max(dp[i], dp[i-a]+1);
        if(i>=b) dp[i]=max(dp[i], dp[i-b]+1);
        if(i>=c) dp[i]=max(dp[i], dp[i-c]+1);
    }
    cout<<dp[n];
}