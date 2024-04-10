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
#define N 200200
#define INF 101111111111111LL
using namespace std;
using python = void;

ll a[N];
ll solve(vector<ll> &wv, ll bc = 29){
	vector<ll> c2[2];
	ll c[2] = {0, 0};
	for(auto i : wv){
		c[(i>>bc)&1]++;
		c2[(i>>bc)&1].pb(i);
	}
	if(bc == 0){
		return (c[0] == 0 || c[1] == 0 ? 0 : 1);
	}
	if(c[0] == 0 || c[1] == 0){
		return solve(wv, bc-1);
	}else{
		return (1LL<<bc)+min(solve(c2[0], bc-1), solve(c2[1], bc-1));
	}
}
signed main(){
	FAST;
	ll n;
	cin >> n;
	vector<ll> inp(n);
	for(ll i =0;i<n;i++) cin >> inp[i];
	cout << solve(inp) << endl;
}