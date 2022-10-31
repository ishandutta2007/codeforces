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
const ll N = 2e5+18;
const ll M= 998244353;
ll x[N], y[N], s[N];
ll dp[N][2];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++) cin >> x[i]>>y[i]>>s[i];
	dp[0][1] = (x[0]+x[0]-y[0])%M;
	dp[0][0] = (s[0] ? dp[0][1] : x[0])%M;
	for(ll i = 1;i<n;i++){
		ll l = -1, r=i;
		while(r-l>1){
			ll m = (l+r)>>1;
			if(x[m] < y[i]) l=m;
			else r=m;
		}
		ll pd1 = (M+dp[i-1][1] + x[i]-x[i-1])%M;
		ll pd0 = (M+dp[i-1][0] + x[i]-x[i-1])%M;

		ll ntt = (l==-1 ? M + pd1 - y[i] : M+M+pd1 - dp[l][1] - y[i] + x[l])%M;
		dp[i][1] = (pd1+ntt)%M;
		dp[i][0] = (s[i] ? pd0+ntt : pd0)%M;
	}
	ll x = (dp[n-1][0]+1)%M;
	cout<<x;
}