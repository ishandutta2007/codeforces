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
const ll N = 228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

ll c[N], c2[N];

python solve(){
	FAST;
	ll n, m, res = 0;
	cin >> n >> m;
	for(ll a, i =0;i<n;i++){
		for(ll j =0;j<m;j++){
			cin >> a;
			if(a == 1) ++c[i], c2[j]++;
		}
	}
	for(ll i = 0;i<n;i++){
		res += (1LL<<c[i])+(1LL<<(m-c[i]))-2;
	}
	for(ll i = 0;i<m;i++){
		res += (1LL<<c2[i])+(1LL<<(n-c2[i]))-2;
	}
	cout << res-n*m << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}