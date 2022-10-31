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
const ll N = 4000002;
ll M;
ll dp[N];
ll sdp[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n >> M;
	dp[n] = 1;
	sdp[n]=1;
	for(ll i = n-1;i>=1;i--){
		dp[i] = sdp[i+1];
		// x/z == i
		for(ll z = 2;i*z<=n;z++){
			ll mn = i*z, mx = min(n, (i+1)*z-1);
			ll u = M+sdp[mn]-sdp[mx+1];
			if(u>=M) u-=M;
			dp[i]+=u;
			if(dp[i]>=M) dp[i]-=M;
		}
		sdp[i]=sdp[i+1]+dp[i];
		if(sdp[i]>=M) sdp[i]-=M;
	}
	cout<<dp[1];
}