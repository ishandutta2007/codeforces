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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll M = 1e9+7;
const ll N = 1228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N], out[N];
bitset<N> b[11];
ll prost[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 0;i<11;i++) b[i].reset();
	for(ll i  =0;i<n;i++){
		cin >> a[i];
		for(ll j = 0;j<11;j++){
			if(a[i]%prost[j] == 0){
				b[j][i] = 1;
			}
		}
	}
	ordered_set osz;
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<11;j++){
			if(b[j][i]){
				out[i] = j;
				osz.insert(j);
				break;
			}
		}
	}
	cout << osz.size() << '\n';
	for(ll i = 0;i<n;i++) cout << osz.order_of_key(out[i])+1 << ' ';
	cout << '\n';
	return;
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}