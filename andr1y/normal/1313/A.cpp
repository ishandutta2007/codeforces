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
	ll a, b, c;
	cin >> a >> b >> c;
	ll r = 0;
	if(a) --a, r++;
	if(b) --b, r++;
	if(c) --c, r++;
	if(a > b) swap(a, b);
	if(b > c) swap(c, b);
	if(a > b) swap(a, b);
	if(c > 0 && a > 0) --c, --a, r++;
	if(b > 0 && a > 0) --b, --a, r++;
	if(c > 0 && b > 0) --c, --b, r++;
	if(a && b && c) ++r;
	cout << r << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}