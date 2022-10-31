#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 300200
#define INF 101111111111111LL
using namespace std;
using python = void;
ll n, m;
ll a[N][10];
ll isne[256];
pair<bool, pll> get(ll ms){
	memset(isne, 0, sizeof(isne));
	for(ll i =0;i<n;i++){
		ll mv= INF;
		for(ll j = 0;j<m;j++) mv=min(mv, a[i][j]);
		if(mv >= ms) return {true, {i, i}};
	}
	for(ll i = 0;i<n;i++){
		ll num = 0, ivn = 0;
		for(ll j= 0;j<m;j++) num += (1LL<<j)*(a[i][j] >= ms ? 1 : 0), ivn += (1LL<<j)*(a[i][j] >= ms ? 0 : 1);
		if(isne[num]!=0){
			return {true, {isne[num]-1, i}};
		}
		for(ll j = 0;j<256;j++){
			if((ivn&j) == ivn) isne[j] = i+1;
		}
	}
	return {false, {0, 0}};
}
signed main(){
	FAST;
	cin >> n >> m;
	for(ll i =0;i<n;i++){
		for(ll j =0;j<m;j++) cin >> a[i][j];
	}
	ll l= 0, r = 1e9;
	while(r-l>1){
		ll ms = (l+r)>>1;
		pair<bool, pll> s = get(ms);
		if(s.x) l = ms;
		else r = ms;
	}
	pair<bool, pll> res = {0, {0, 0}};
	for(ll ms = r;ms>=l && !res.x;ms--) if(get(ms).x){res = get(ms);}
	cout << res.y.x+1 << " " << res.y.y+1 << endl;
}