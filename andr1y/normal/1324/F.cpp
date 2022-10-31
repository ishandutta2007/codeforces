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
ll dp[N];
ll a[N];
ll ans[N];
vector<ll> d[N];
void dc1(ll v, ll p = -1){
	dp[v] = a[v];
	for(auto i : d[v]){
		if(i==p)continue;
		dc1(i, v);
		dp[v] += max(dp[i], 0ll);
	}
}
void dc2(ll v, ll p = -1){
	ans[v] = dp[v];
	for(auto i : d[v]){
		if(i==p) continue;
		dp[v] -= max(0ll, dp[i]);
		dp[i] += max(0ll, dp[v]);
		dc2(i, v);
		dp[i] -= max(0ll, dp[v]);
		dp[v] += max(0ll, dp[i]);
	}
}
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0) a[i] = -1;
	}
	for(ll a, b, i = 0;i<n-1;i++){
		cin >> a >> b;
		d[a].pb(b);
		d[b].pb(a);
	}
	dc1(1);
	dc2(1);
	for(ll i = 1;i<=n;i++) cout << ans[i] << ' ';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}