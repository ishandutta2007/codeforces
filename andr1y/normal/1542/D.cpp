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
const ll N = 502;
const ll M = 998244353;
ll dp[N][N];
ll a[N];
ll pw[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	pw[0]=1;
	for(ll i = 1;i<N;i++) pw[i]=(pw[i-1]*2)%M;
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		char c;cin>>c;
		if(c=='-') a[i]=-1;
		else cin >> a[i];
	}
	ll res=0;
	for(ll el=0;el<n;el++){
		if(a[el]==-1) continue;
		memset(dp, 0, sizeof(dp));
		if(el){
			dp[0][0]=1;
			if(a[0]<a[el]&&a[0]>0) dp[0][1]++;
			else dp[0][0]++;
		}else{
			dp[0][1]=1;
		}
		//left part
		for(ll tj=1;tj<el;tj++){
			for(ll fk=0;fk<=tj;fk++){
				if(a[tj]==-1){
					dp[tj][fk] = (dp[tj][fk]+dp[tj-1][fk])%M;
					dp[tj][max(0ll, fk-1)] = (dp[tj][max(0ll, fk-1)]+dp[tj-1][fk])%M;
				}else if(a[tj]<a[el] ){
					// counts as less
					dp[tj][fk] = (dp[tj][fk]+dp[tj-1][fk])%M;
					dp[tj][fk+1] = (dp[tj][fk+1]+dp[tj-1][fk])%M;
				}else{
					dp[tj][fk]=(dp[tj-1][fk]*2)%M;
				}
			}
		}
		//TJ
		if(el){
			for(ll fk=0;fk<=el;fk++){
				dp[el][fk+1] = (dp[el-1][fk]);
			}
		}
		//right part
		for(ll tj = el+1;tj<n;tj++){
			for(ll fk = 1;fk<=tj;fk++){
				// from dp[j-1][k] -> (dp[j][k] and dp[j][k]) or (dp[j][k+1] and dp[j][k]) or (dp[j][k] and dp[j][k-1])
				if(a[tj]==-1){
					dp[tj][fk] = (dp[tj][fk]+dp[tj-1][fk])%M;
					dp[tj][fk-1] = (dp[tj][fk-1]+dp[tj-1][fk])%M;
				}else if(a[tj]<=a[el]){
					dp[tj][fk] = (dp[tj][fk]+dp[tj-1][fk])%M;
					dp[tj][fk+1] = (dp[tj][fk+1]+dp[tj-1][fk])%M;
				}else{
					dp[tj][fk]=(dp[tj-1][fk]*2)%M;
				}
			}
		}
		ll tres=0;
		for(ll i = 1;i<=n;i++) tres=(tres+dp[n-1][i])%M;
		tres=(tres*a[el])%M;
		res=(tres+res)%M;
	}
	cout<<res;
}