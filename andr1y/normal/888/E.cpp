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
const ll N = 3e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[N];
ll b[N], bc = 0;

python solve(){
	FAST;
	ll n, m;
	cin >> n >> m;
	ll rvvv = 0;
	for(ll  i=0;i<n;i++){
		cin >> a[i];
		a[i] %= m;
		rvvv = max(rvvv, a[i]);
	}
	ll xc = (n>>1)+(n&1), yc = n-xc;
	for(ll i = 1;i<(1LL<<xc);i++){
		ll sm = 0;
		for(ll j = 0;j<xc;j++){
			if((i>>j)&1){
				sm = (sm+a[j])%m;
			}
		}
		b[bc++] = sm;
	}
	sort(b, b+bc);
	for(ll i = 1;i<(1LL<<yc);i++){
		ll sm = 0;
		for(ll j = 0;j<yc;j++){
			if((i>>j)&1){
				sm = (sm+a[xc+j])%m;
			}
		}
		ll mv = m-1-sm;
		ll xv = max(sm, (sm+b[bc-1])%m);
		ll l = 0, r = bc-1;
		while(r-l>1){
			ll rm = (l+r)>>1;
			if(b[rm] <= mv) l = rm;
			else r = rm;
		}
		for(ll rm = l;rm<=r;rm++) xv = max(xv, (sm+b[rm])%m);
		rvvv = max(rvvv, xv);
	}
	cout << rvvv << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}