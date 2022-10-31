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
	ll n, m, k, e;
	cin >> n >> m >> k;
	for(ll i = 0;i<k;i++) cin >> e >> e;
	for(ll i = 0;i<k;i++) cin >> e >> e;
	string res = "";
	for(ll i = 1;i<m;i++) res+= 'L';
	for(ll i = 1;i<n;i++) res+= 'U';
	for(ll i = 0;i<n;i++){
		for(ll j = 1;j<m;j++){
			if(i&1) res+= 'L';
			else res+= 'R';
		}
		if(i!=n-1) res+='D';
	}
	cout << res.length() << '\n' << res;
	cout << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}