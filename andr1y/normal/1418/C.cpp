// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N], dp[N][2];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            dp[i][0]=inf;
            dp[i][1]=inf;
        }
        dp[0][1] = a[0];
        dp[1][1] = a[0]+a[1];
        dp[1][0] = a[0];
        for(ll i = 2;i<n;i++){
            dp[i][0] = min(dp[i-1][1], dp[i-2][1]);
            dp[i][1] = min(dp[i-1][0]+a[i], dp[i-2][0]+a[i]+a[i-1]);
        }
        cout<<min(dp[n-1][0], dp[n-1][1])<<'\n';
	}
}