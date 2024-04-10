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
ll a[N], pof[N];
vector<ll> po2;
python solve(){
	FAST;
	ll n, k;
	cin >> n >> k;
	for(ll i  =0;i<n;i++){
		cin >> a[i];
		pof[a[i]] = i;
	}
	ll a1 = 0, a2 = 1;
	for(ll ii = 0;ii<k;ii++){
		ll i  = n-ii;
		a1 += i;
		po2.pb(pof[i]);
	}
	sort(itr(po2));
	for(ll i = 1;i<po2.size();i++){
		a2 = a2*(po2[i]-po2[i-1]);
		a2 %= M;
	}
	cout << a1 << ' ' << a2 << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}