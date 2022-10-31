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
const ld EPS = 1e-9;
ld a[N];
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++){
		ll e;
		cin >> e;
		a[i] = e;
	}
	for(ll Q = 0;Q<66;Q++){
		ld ts = 0;
		ll bg = 0;
		for(ll i =0;i<n;i++){
			if(i == 0){
				ts += a[i];
			}else{
				if(a[i] <= a[i-1]+EPS){
					ts+=a[i];
				}else{
					for(ll j = bg;j<i;j++) a[j] = ts/(i-bg);
					bg = i;
					ts = a[i];
				}
			}
		}
		for(ll j = bg;j<n;j++) a[j] = ts/(n-bg);
	}
	cout << fixed << setprecision(10);
	for(ll i =0;i<n;i++){
		cout << a[i] << '\n';
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