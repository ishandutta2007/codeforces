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
const ll N = 1e7+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

ll to[N][2];
ll ec[N];
ll sz = 1;
void add(ll num){
	ll root = 1;
	ec[1]++;
	for(ll i = 31;i>=0;--i){
		ll bit = (num>>i)&1;
		if(to[root][bit]== 0){
			to[root][bit] = ++sz;
			root = sz;
		}else{
			root = to[root][bit];
		}
		ec[root]++;
	}
}
void remove(ll num){
	ll root = 1;
	ec[1]--;
	for(ll i = 31;i>=0;--i){
		ll bit = (num>>i)&1;
		root = to[root][bit];
		assert(root != 0);
		ec[root]--;
	}
}
ll get(ll num){
	ll root = 1, ans= 0;
	for(ll i = 31;i>=0;--i){
		ll bit = (num>>i)&1;
		ll ib = (bit+1)&1;
		if(to[root][ib] != 0 && ec[to[root][ib]] > 0){
			root = to[root][ib];
			ans += (1LL<<i);
		}else{
			root = to[root][bit];
		}
	}
	return ans;
}


python solve(){
	FAST;
	ll q, e;
	char c;
	cin >> q;
	add(0);
	while(q--){
		cin >> c >> e;
		if(c == '+'){
			add(e);
		}else if(c == '-'){
			remove(e);
		}else{
			cout << get(e) << '\n';
		}
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