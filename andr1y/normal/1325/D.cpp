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
vector<ll> ans;
vector<ll> nans;
bool ban[140];
void spoof(){
	memset(ban, 0, sizeof(ban));
	nans.clear();
	ll n = ans.size();
	for(ll i =0;i<n;i++){
		if(ban[i]) continue;
		ban[i] = 1;
		bool ok = 0;
		for(ll j = i+1;j<n;j++){
			if(ban[j]) continue;
			if(ans[i] + ans[j] == (ans[i]|ans[j])) {
				ok =1;
				nans.pb(ans[i]|ans[j]);
				ban[j] = 1;
				break;
			}
		}
		if(!ok) nans.pb(ans[i]);
	}
	swap(ans, nans);
}
python solve(){
	FAST;
	ll u, v;
	cin >> u >> v;
	if(u > v) cout << -1;
	else{
		if(u) ans.pb(u);
		ll df = v-u;
		if(df&1){
			cout << -1;
		}else{
			df>>=1;
			for(ll i=0;i<60;i++){
				if(df&1){
					ans.pb(1LL<<i);
					ans.pb(1LL<<i);
				}
				df>>=1;
			}
			for(ll i = 0;i<130;i++) spoof();
			cout << ans.size() << '\n';
			for(auto i : ans) cout << i << ' ';
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