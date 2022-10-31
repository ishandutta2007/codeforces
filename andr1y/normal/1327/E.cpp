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

const ll M = 998244353;
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll bpm(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a%M;
	if(b&1) return (a*bpm((a*a)%M, b/2))%M;
	else return bpm((a*a)%M, b/2);
}
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 1;i<=n;i++){
		if(i == n){
			cout << 10 << ' ';
		}else if(i == n-1){
			cout << 180 << ' ';
		}else{
			ll v = 10*9*bpm(10, n-i-1)*2;
			v %= M;
			v += (10*9*9*bpm(10, n-i-2)*(n-i-1))%M;
			v %= M;
			cout << v << ' ';
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