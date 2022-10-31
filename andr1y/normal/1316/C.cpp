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
const ll N = 1e6+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
random_device rd;
mt19937 gen(rd());
ll a[N], b[N];
python solve(){
	FAST;
	ll n, m, p;
	cin >> n >> m >> p;
	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<n;i++) a[i]%=p;
	for(ll i=0;i<m;i++) cin >> b[i];
	for(ll i=0;i<m;i++) b[i]%=p;
	ll ii = 0;
	while(a[ii] == 0) ++ii;
	ll ij = 0;
	while(b[ij] == 0) ++ij;
	cout << ii+ij << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}