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
vector<ll> d[N];
ll dp[N], fc=0, mx=0;
char st[N];
void dfs(ll v){
	st[v]=1;
	for(auto i : d[v]){
		if(st[i]==1) {fc=1;break;}
		if(st[i]!=2) dfs(i);
		dp[v] = max(dp[v], dp[i]+(v>i ? 1 : 0));
	}
	st[v]=2;
	mx=max(mx, dp[v]);
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i = 0;i<n;i++) d[i].clear(), dp[i]=0, st[i]=0;
		for(ll i = 0;i<n;i++){
			ll sz, a;
			cin >> sz;
			while(sz--){
				cin >> a;
				d[a-1].push_back(i);
			}
		}
		fc=0, mx=0;
		for(ll i = 0;i<n&&!fc;i++){
			if(st[i]!=2) dfs(i);
		}
		if(fc) cout<<"-1\n";
		else cout<<mx+1<<'\n';
	}
}