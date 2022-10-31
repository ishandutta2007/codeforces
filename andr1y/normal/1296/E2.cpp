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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll M = 1e9+7;
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[N];
ll maxdp[26];
python solve(){
	FAST;
	dp[0] = inf;
	ll len = 0;
	ll n;
	string s;
	cin >> n >> s;
	for(ll i = 0;i<n;i++){
		ll c = s[i]-'a';
		if(c == 25){
			dp[i] = 1;
			maxdp[25] = 1;
		}else{
			dp[i] = *max_element(maxdp+c+1, maxdp+26)+1;
			maxdp[c] = max(maxdp[c], dp[i]);
		}
	}
	cout << *max_element(maxdp, maxdp+26) << '\xa';
	for(ll i =0;i<n;i++) cout << dp[i] << '\x20';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}