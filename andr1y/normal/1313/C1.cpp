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
const ll N = 5e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N], res[N];
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++) cin >> a[i];
		ll mv = 0, mp = -1;
	for(ll i =0;i<n;i++){
		ll sum = a[i], xx = a[i];
		for(ll j = i-1;j>=0;j--){
			xx = min(xx, a[j]);
			sum += xx;
		}
		xx = a[i];
		for(ll j = i+1;j<n;j++){
			xx = min(xx, a[j]);
			sum += xx;
		}
		if(sum > mv){
			mv = sum;
			mp= i;
		}
	}
	ll xx = a[mp];
	res[mp] = xx;
	for(ll j = mp-1;j>=0;j--){
		xx = min(xx, a[j]);
		res[j] = xx;
	}
	xx = a[mp];
	for(ll j = mp+1;j<n;j++){
		xx = min(xx, a[j]);
		res[j] = xx;
	}
	for(ll i =0;i<n;i++) cout << res[i] << ' ';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}