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
const ll N = 1e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

pll gkf(pll a, pll b){
	ll A = a.y-b.y;
	ll B = b.x-a.x;
	// ll g = __gcd(abs(A), abs(B));
	// A/=g;
	// B/=g;
	if(A < 0){
		A=-A;
		B=-B;
	}
	if(A == 0){
		if(B < 0) B = -B;
	}
	return {A, B};
}
map<pll, ll> cnt;
pll a[N];

python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].x >> a[i].y;
		if(i != 0){
			pll line = gkf(a[i], a[i-1]);
			cnt[line]++;
		}
		if(i == n-1){
			pll line = gkf(a[0], a[i]);
			cnt[line]++;
		}
	}
	if(n&1){
		cout << "NO\n";
		return;
	}
	bool ok = 1;
	for(auto i : cnt) ok = ok & ((i.y&1)==0);
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}