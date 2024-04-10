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
const ll N = 228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
pair<ll, pll> a[N];
python solve(){
	FAST;
	ll n, m;
	cin >> n >> m;
	a[0] = {0, {m, m}};
	for(ll i =1;i<=n;++i){
		cin >> a[i].x >> a[i].y.x >> a[i].y.y;
	}
	sort(a, a+n+1);
	ll l = m, r = m;
	for(ll i = 1;i<=n;++i){
		ll dd = a[i].x - a[i-1].x;
		l -= dd;
		r += dd;
		ll xl = a[i].y.x, xr = a[i].y.y;
		l = max(xl, l);
		r = min(xr, r);
		if(l > r) break;
	}
	if(l > r) cout << "NO\n";
	else cout << "YES\n";
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}