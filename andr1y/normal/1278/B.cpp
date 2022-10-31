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
	ll a, b;
	cin >> a >> b;
	ll df = max(a, b) - min(a, b);
	ll l = 0, r = 1e9;
	while(r-l>1){
		ll m = (l+r)>>1;
		if((m*(m+1))/2 <= df) l =m;
		else r = m;
	}
	ll res= -1;
	for(ll m = l;m<=r;m++){
		if((m*(m+1))/2 <= df) res = m;
	}
	assert(res >= 0);
	if((res*(res+1))/2 == df){
		cout << res << '\n';
		return;
	}
	++res;
	while(((res*(res+1))/2-df)%2 == 1) ++res;
	cout << res << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}