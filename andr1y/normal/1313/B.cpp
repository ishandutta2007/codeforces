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
	ll n, x, y;
	cin >> n >> x >> y;
	ll ok = 0;
	// if(y == n){
	// 	if(x == 1){
	// 		cout << n << " " << n << '\n';
	// 		return;
	// 	}else{
	// 		cout << max(n-x-1, 1ll) << " " << n << '\n';
	// 		return;
	// 	}
	// }
	if(x > y) swap(x, y);
	ll s1 = min(max(0ll, n-y-1), x-1);
	ll s2 = min(y-1, max(0ll, n-x-1));
	ll s3 = min(n-y-s1, n-x-s2);
	ll prs = s1+s2+s3;
	ok = n-prs;

	s1 = min(n-x, y-1);
	s2 = min(n-y, x-1);
	s3 = min(y-1-s1, x-1-s2);
	ll bad = s1+s2+s3+1;

	cout << ok << " " << bad << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}