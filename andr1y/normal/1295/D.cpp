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

python solve(){
	FAST;
	ll n, m;
	cin >> n >> m;
	ll g = __gcd(n, m);
	ll e = m/g;
	ll k = n/g;
	vector<ll> prms;
	prms.reserve(10);
	ll oe = e;
	for(ll i = 2;i*i<=e;i++){
		if(oe%i == 0){
			prms.pb(i);
			while(oe%i == 0) oe/=i;
		}
	}
	if(oe>1) prms.pb(oe);
	oe = e;
	for(ll mask = 1;mask<(1LL<<prms.size());mask++){
		ll val = 0, db = 1;
		for(ll j =0;j<prms.size();j++){
			if(mask&(1LL<<j)){
				db *= prms[j];
			}
		}
		ll u = k%db;
		ll dl = (db-u)%db;
		if(dl > oe-1) continue;
		val+=(oe-1-dl)/db+1;
		if(__builtin_popcountll(mask)&1) e -= val;
		else e += val;
	}
	cout << e << '\x0a';
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}