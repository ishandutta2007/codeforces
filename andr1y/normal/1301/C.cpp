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
ll n, m;
ll cnt(ll xm){
	if(xm == 0) return 0;
	if(xm == n) return n;
	ll e = (n-m)/xm;
	ll eb = (n-m)%xm;
	ll vv = eb*(((e+1)*(e+2))>>1) + (xm-eb)*((e*(e+1))>>1);
	return vv;
}
python solve(){
	FAST;
	cin >> n >> m;
	if(m == 0){
		cout << "0\n";
	}else{
		ll mnn = 0;
		if(m == 1){
			if(n == 1) mnn = 0;
			else mnn = min(cnt(1), cnt(2));
		}else if(m == n-1){
			mnn = 1;
		}else if(m == n){
			mnn = 0;
		}else mnn = min(cnt(m-1), min(cnt(m), cnt(m+1)));
		cout << ((n*(n+1))>>1)-mnn << '\n';
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