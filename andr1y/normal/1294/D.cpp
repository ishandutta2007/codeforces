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

ll n, a[N];
pll t[4*N];
pll xmin(const pll &a, const pll &b){
	if(a.x==b.x) return (a.y < b.y ? a : b);
	else return (a.x < b.x ? a : b);
}
void build(ll v, ll tl, ll tr){
	if(tl == tr){
		t[v] = {0, tl};
		return;
	}
	ll tm = (tl+tr)>>1;
	build(v+v, tl, tm);
	build(v+v+1, tm+1, tr);
	t[v] = xmin(t[v+v], t[v+v+1]);
}
void update(ll v, ll tl, ll tr, ll pos, ll delta){
	if(tl == tr && tl == pos) t[v].x+=delta;
	if(tl == tr) return;
	ll tm = (tl+tr)>>1;
	if(pos >= tl && pos <= tm) update(v+v, tl, tm, pos, delta);
	if(pos >= tm+1 && pos <= tr) update(v+v+1, tm+1, tr, pos, delta);
	t[v] = xmin(t[v+v], t[v+v+1]);
}

python solve(){
	FAST;
	ll q, x, a;
	cin >> q >> x;
	build(1, 1, x);
	while(q--){
		cin >> a;
		update(1, 1, x, a%x+1, 1);
		ll vl = t[1].x*x + t[1].y-1;
		cout << vl << '\n';
	}
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}