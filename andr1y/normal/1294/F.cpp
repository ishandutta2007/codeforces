#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

ll n;
vector<ll> d[N];
ll h[N], dp[N][2], xxc[N][2][3], dpst[N], dxst[N];
python dfs(ll v, ll p = 0){
	h[v] = h[p]+1;
	dpst[v] = h[v];
	dxst[v] = v;
	multiset<pll, greater<pll>> mst;
	for(auto i : d[v]){
		if(i == p) continue;
		dfs(i, v);
		if(dpst[i] > dpst[v]){
			dpst[v] = dpst[i];
			dxst[v] = dxst[i];
		}
		mst.insert({dpst[i], i});
		if(dpst[i]-h[v] > dp[v][0]){
			dp[v][0]= dpst[i]-h[v];
			xxc[v][0][0] = dxst[i];
			xxc[v][0][1] = v;
		}
		if(dp[v][0] < dp[i][0]+1){
			dp[v][0] = dp[i][0]+1;
			xxc[v][0][0] = xxc[i][0][0];
			xxc[v][0][1] = xxc[i][0][1];
		}
		if(dp[v][1] < dp[i][0]+1){
			dp[v][1] = dp[i][0]+1;
			xxc[v][1][0] = xxc[i][0][0];
			xxc[v][1][1] = xxc[i][0][1];
			xxc[v][1][2] = v;
		}
		if(dp[v][1] < dp[i][1]){
			dp[v][1] = dp[i][1];
			xxc[v][1][0] = xxc[i][1][0];
			xxc[v][1][1] = xxc[i][1][1];
			xxc[v][1][2] = xxc[i][1][2];
		}
	}

	if(d[v].size() >= 2+(p == 0 ? 0 : 1)){
		pll v1 = *(mst.begin()), v2 = *(next(mst.begin(), 1));
		if(v1.x+v2.x-2*h[v] > dp[v][0]){
			dp[v][0] = v1.x+v2.x-2*h[v];
			xxc[v][0][0] = dxst[v1.y];
			xxc[v][0][1] = dxst[v2.y];
			if(dp[v][0] > dp[v][1]){
				dp[v][1] = dp[v][0];
				xxc[v][1][0] = dxst[v1.y];
				xxc[v][1][1] = dxst[v2.y];
				xxc[v][1][2] = v;
			}
		}
		for(auto i : d[v]){
			ll xv = dp[i][0]+1;
			ll xe = (i == v1.y ? v2.y : v1.y);
			if(xv+dpst[xe]-h[v] > dp[v][1]){
				dp[v][1] = xv+dpst[xe]-h[v];
				xxc[v][1][0] = xxc[i][0][0];
				xxc[v][1][1] = xxc[i][0][1];
				xxc[v][1][2] = dxst[xe];
			}
		}
	}
	if(d[v].size() >= 3+(p == 0 ? 0 : 1)){
		pll v1 = *(mst.begin()), v2 = *(next(mst.begin(), 1)), v3 = *(next(mst.begin(), 2));
		if(v1.x+v2.x+v3.x-3*h[v] > dp[v][1]){
			dp[v][1] = v1.x+v2.x+v3.x-3*h[v];
			xxc[v][1][0] = dxst[v1.y];
			xxc[v][1][1] = dxst[v2.y];
			xxc[v][1][2] = dxst[v3.y];
		}
	}
}

python solve(){
	FAST;
	cin >> n;
	for(ll a,b, i =1;i<n;i++){
		cin >> a >> b;
		d[a].pb(b);
		d[b].pb(a);
	}
	dfs(1);
	cout << dp[1][1] << '\n';
	cout << xxc[1][1][0] << " " << xxc[1][1][1] << " " << xxc[1][1][2] << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}