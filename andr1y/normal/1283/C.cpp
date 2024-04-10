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
ll a[N], dr[N];

python solve(){
	FAST;
	cin >> n;
	set<ll> f1, f2;
	for(ll i =1;i<=n;i++){
		cin >> a[i];
		dr[a[i]] = i;
		if(a[i] == 0) f1.insert(i);
	}
	vector<ll> kpss;
	for(ll i = 1;i<=n;i++){
		if(a[i] == 0 && dr[i] == 0) kpss.pb(i);
		if(dr[i] == 0) f2.insert(i);
	}
	if(kpss.size() == 0){
		//cnt
	}else if(kpss.size() == 1){
		f1.erase(kpss[0]);
		ll p = *f2.begin(), xp = -1;
		if(p == kpss[0]){
			xp = 1;
			f2.erase(f2.begin());
			p = *f2.begin();
		}
		f2.erase(f2.begin());
		a[kpss[0]] = p;
		dr[p] = kpss[0];
		if(xp == 1){
			f2.insert(kpss[0]);
		}
	}else{
		for(ll i = 0;i<kpss.size();i++){
			ll p = kpss[(i+1)%kpss.size()];
			a[kpss[i]] = p;
			dr[p] = kpss[i];
			f1.erase(kpss[i]);
			f2.erase(p);
		}
	}
	while(!f1.empty()){
		ll p = *f1.begin();
		f1.erase(f1.begin());
		ll p2 = *f2.begin();
		f2.erase(f2.begin());
		a[p] = p2;
		dr[p2] = p;
	}
	for(ll i =1;i<=n;i++) cout << a[i] << char(32);
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}