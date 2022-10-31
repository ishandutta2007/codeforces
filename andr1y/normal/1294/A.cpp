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

ll n, k;

python solve(){
	FAST;
	ll a, b, c;
	cin >> a >> b >> c >> n;
	ll mx = max(a, max(b, c));
	ll df = 3*mx-a-b-c;
	n-=df;
	if(n>=0 && n%3==0) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}