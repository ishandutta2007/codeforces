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
const ll N = 19;
ll d[N][N];
ll dp[1<<N][N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for(ll a, b, i=0;i<m;i++){
		cin >> a >> b;
		--a, b--;
		d[a][b]=d[b][a]=1;
	}
	ll res=0;
	for(ll i = 0;i<n;i++){
		memset(dp, 0, sizeof dp);
		dp[1<<i][i]=1;
		for(ll mask = (1<<i);mask<(1<<n);mask+=(1<<i)){
			for(ll last=i;last<n;last++){
				for(ll next=i+1;next<n;next++){
					if(d[last][next] && (~mask>>next)&1){
						dp[mask|(1<<next)][next]+=dp[mask][last];
					}
				}
				if(d[last][i] && __builtin_popcount(mask)>2) res+=dp[mask][last];
			}
		}
	}
	res>>=1;
	cout<<res;
}