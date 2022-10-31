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
const ll N = 1e5+18;
const ll M = 998244353;
ll ans[N];
ll l[N], r[N];
ll xl[N], xr[N];
ll dp[N], sdp[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for(ll i = 0;i<n;i++) cin >> l[i]>>r[i];
	for(ll g = m;g>=1;g--){
		bool cnt=0;
		for(ll i = 0;i<n;i++){
			xl[i]=(l[i]+g-1)/g;
			xr[i]=(r[i])/g;
			if(xl[i]>xr[i]) {
				cnt=1;
				break;
			}
		}
		if(cnt) continue;
		ll om = (m/g);
		for(ll i = 0;i<=om;i++) dp[i]=0;
		dp[0]=1;
		for(ll i = 0;i<n;i++){
			sdp[0]=dp[0];
			for(ll j=1;j<=om;j++){
				sdp[j]=(sdp[j-1]+dp[j]);
				if(sdp[j]>=M) sdp[j]-=M;
			}
			for(ll j=om;j>=xl[i];j--){
				ll x = M + sdp[j-xl[i]] - (j-xr[i]>0 ? sdp[j-xr[i]-1] : 0);
				if(x>=M) x-=M;
				dp[j]=x;
			}
			for(ll j = xl[i]-1;j>=0;j--) dp[j]=0;
		}
		ll res=0;
		for(ll i = 0;i<=om;i++) res=(res+dp[i]);
		for(ll j = g+g;j<=m;j+=g) res = M+res-ans[j];
		res%=M;
		ans[g]=res;
	}
	cout<<ans[1];
}