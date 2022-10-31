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
const ll N = 1e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
bitset<N> a, b;
python solve(){
	FAST;
	a.reset();
	b.reset();
	ll n;
	cin >> n;
	for(ll i = 1;i<=n;i++){
		ll k;
		cin >> k;
		for(ll e, j = 0;j<k;j++){
			cin >> e;
			if(!a[e] && !b[i]){
				a[e] = 1;
				b[i] = 1;
			}
		}
	}
	ll cc = b.count();
	if(cc == n){
		cout << "OPTIMAL\n";
	}else{
		cout << "IMPROVE\n";
		ll ff = 1;
		while(b[ff]) ++ff;
		ll fs = 1;
		while(a[fs]) ++fs;
		cout << ff << ' ' << fs << '\n';
	}
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}