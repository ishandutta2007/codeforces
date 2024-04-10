//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = (1<<20)+13;
const ld eps = 1e-9;
ld v;
void dfs(ld c, ld m, ld vn, ll len, ld &res){
	if(c>eps&&m>eps){
		if(1){
			// with c
			ld ov = vn*c;
			ld tsp = min(v, c);
			ld nc = c-tsp;
			ld nm = m+tsp/2;
			res+=(1-nc-nm)*ov*len;
			dfs(nc, nm, ov, len+1, res);
		}
		if(1){
			// with m
			ld ov = vn*m;
			ld tsp = min(v, m);
			ld nc = c+tsp/2;
			ld nm = m-tsp;
			res+=(1-nc-nm)*ov*len;
			dfs(nc, nm, ov, len+1, res);
		}
	}else if(c>eps){
		// with c
		ld ov = vn*c;
		ld tsp = min(v, c);
		ld nc = c-tsp;
		ld nm = 0;
		res+=(1-nc-nm)*ov*len;
		dfs(nc, nm, ov, len+1, res);
	}else if(m>eps){
		// with m
		ld ov = vn*m;
		ld tsp = min(v, m);
		ld nc = 0;
		ld nm = m-tsp;
		res+=(1-nc-nm)*ov*len;
		dfs(nc, nm, ov, len+1, res);
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ld c, m, p;cin>>c>>m>>p>>v;
		ld res = p;
		dfs(c, m, 1, 2, res);
		cout<<fixed<<setprecision(12)<<res<<'\n';
	}
}