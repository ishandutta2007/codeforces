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
const ll N = 4e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;


vector<ll> t[4*N];
ll xz[N];
void build(ll v, ll tl, ll tr){
	if(tl == tr){
		t[v].clear();
		t[v].pb(xz[tl]);
		return;
	}
	ll tm = (tl+tr)>>1;
	build(v+v, tl, tm);
	build(v+v+1, tm+1, tr);
	t[v].resize(t[v+v].size()+t[v+v+1].size());
	merge(itr(t[v+v]), itr(t[v+v+1]), t[v].begin());
}
ll get(ll v, ll tl, ll tr, ll l, ll r, ll val){
	if(tl >= l && tr <= r){
		auto lower = lower_bound(itr(t[v]), val);
		auto upper = upper_bound(itr(t[v]), val);
		return distance(lower, upper);
	}
	ll tm = (tl+tr)>>1;
	ll s = 0;
	if(r >= tl && l <= tm) s+=get(v+v, tl, tm, l, r, val);
	if(r >= tm+1 && l<=tr) s+=get(v+v+1, tm+1, tr, l, r, val);
	return s;
}



vector<ll> a[N];

python solve(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll k, i = 0;i<n;i++){
		for(ll j = 0;j<m;j++){
			cin >> k;
			a[j].pb(k);
		}
	}
	ll sr = 0;
	for(ll i = 0;i<m;i++){
		ll ts = 0;
		for(ll j = 0;j<a[i].size();j++){
			ll el = a[i][j];
			if((el-1)%m != i) xz[j+1] = inf;
			else{
				ll szp = j-(el-1)/m;
				xz[j+1] = szp;
			}
		}
		build(1, 1, n);
		ll mr = inf;
		for(ll j = 0;j<n;j++){
			ll r = j+
				(n-j)-(get(1, 1, n, j+1, n, j))+
				(j > 0 ? (j - get(1, 1, n, 1, j, -n+j)) : 0);
			mr = min(mr, r);
		}
		sr += mr;
	}
	cout << sr << endl;
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}