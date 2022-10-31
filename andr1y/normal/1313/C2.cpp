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
ll dp1[N], dp2[N];
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++) cin >> a[i];
	stack<pll> st;
	for(ll i = 0;i<n;i++){
		ll xs = 1;
		while(!st.empty() && st.top().x > a[i]){
			xs+=st.top().y;
			st.pop();
		}
		dp1[i] = (st.empty() ? 0 : dp1[i-xs]) + xs*a[i];
		st.push({a[i], xs});
	}
	while(!st.empty()) st.pop();
	for(ll i = n-1;i>=0;i--){
		ll xs = 1;
		while(!st.empty() && st.top().x > a[i]){
			xs+=st.top().y;
			st.pop();
		}
		dp2[i] = (st.empty() ? 0 : dp2[i+xs]) + xs*a[i];
		st.push({a[i], xs});
	}
	ll mv = 0, mp = -1;
	for(ll i =0;i<n;i++){
		ll xx = a[i];
		if(i > 0)   xx += dp1[i] - a[i];
		if(i+1 < n) xx += dp2[i] - a[i];
		if(xx > mv){
			mv = xx;
			mp = i;
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