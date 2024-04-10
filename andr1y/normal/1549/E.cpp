//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 3e6+18;
const ll M = 1e9+7;
ll f[N], of[N];
ll dp[N][3];
ll ans[N];
ll bpm(ll a, ll b){
	if(b==0) return 1;
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}
ll c(ll n, ll k){
	return ((f[n]*of[k])%M)*of[n-k] %M;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, q;
	cin >> n >> q;
	dp[0][0]=n, dp[0][1]=n, dp[0][2]=n;
	f[0]=1;
	for(ll i = 1;i<N;i++) f[i]=(f[i-1]*i)%M;
	of[N-1]=bpm(f[N-1], M-2);
	for(ll i = N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M;
	ll x = (f[0]*of[0])%M;
	ans[0]=dp[0][0]+c(3*n, 0);
	for(ll i = 1;i<=3*n;i++){
		//sdp = (sdp + M - c(3*n, i))%M;
		// dp[1] = dp[0] + dp[i-1][0]
		// dp[2] = dp[1] + dp[i-1][1]
		// dp[0]+dp[1]+dp[2]=sdp=dp[0] +dp[0]+dp[1]+dp[i-1][0]+dp[i-1][1]=dp[0]+dp[0]+dp[0]+dp[i-1][0]+dp[i-1][0]+dp[i-1][1]
		// === 3*dp[0] + 2*dp[i-1][0] + dp[i-1][1]
		dp[i][0] = (c(3*n, i+1) + M - dp[i-1][1] + M + M - dp[i-1][0]*2)%M;
		dp[i][0] = (dp[i][0]*333333336)%M;
		dp[i][1] = (dp[i][0]+dp[i-1][0])%M;
		dp[i][2] = (dp[i][1]+dp[i-1][1])%M;
		ans[i] = (dp[i][0]+c(3*n, i))%M;
	}
	while(q--){
		ll x;
		cin >> x;
		cout<<ans[x]<<'\n';
	}
}