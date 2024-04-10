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
ll cnt[64];
ll a[N];
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++){
		cin >> a[i];
		for(ll c = 0;c<60;c++){
			cnt[c] += (a[i]>>c)&1;
		}
	}
	sort(a, a+n, greater<ll>());
	ll fst = -1;
	for(ll c = 59;c>=0;c--){
		if(cnt[c] == 1){
			for(ll i = 0;i<n;i++){
				if((a[i]>>c)&1){
					fst = i;
					break;
				}
			}
			if(fst != -1) break;
		}
	}
	if(fst != -1){
		swap(a[0], a[fst]);
	}
	for(ll i =0;i<n;i++){
		cout << a[i] << " ";
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