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
vector<pll> d[N];
ll edges[N];
pll p[N];
ll tin[N], tout[N], timer = 0;
void dfs(ll v, ll pr = -1, ll cb = -1){
	p[v] = {pr, cb};
	tin[v] = ++timer;
	for(auto i :d[v]){
		if(i.x != pr) dfs(i.x, v, i.y);
	}
	tout[v] = ++timer;
}
bool upper(ll a, ll b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
vector<pair<pll, pll>> qs;
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll a, b, i =0;i<n-1;i++){
		cin >> a >> b;
		d[a].pb({b, i});
		d[b].pb({a, i});
	}

	dfs(1);

	ll q;
	cin >> q;
	while(q--){
		ll a, b, c;
		cin >> a >> b >> c;
		ll oa = a;
		while(!upper(oa, b)){
			edges[p[oa].y] = max(edges[p[oa].y], c);
			oa = p[oa].x;
		}
		ll ob = b;
		while(!upper(ob, a)){
			edges[p[ob].y] = max(edges[p[ob].y], c);
			ob = p[ob].x;
		}
		assert(oa==ob);
		qs.pb({{a, b}, {c, oa}});
	}

	bool ok = 1;
	for(auto i : qs){
		ll oa= i.x.x, ob = i.x.y, mv = inf;
		while(oa!=i.y.y){
			if(edges[p[oa].y] > 0) mv = min(edges[p[oa].y], mv);
			oa=p[oa].x;
		}
		while(ob!=i.y.y){
			if(edges[p[ob].y] > 0) mv = min(edges[p[ob].y], mv);
			ob=p[ob].x;
		}
		ok = ok & (mv == i.y.x);
	}

	if(ok){
		for(ll i =0;i<n-1;i++){
			if(!edges[i]) cout << "1000000 ";
			else cout << edges[i] << " ";
		}
	}else cout << "-1\xa";
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}