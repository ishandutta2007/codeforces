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
const ll N = 4e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N];
python solve(){
	FAST;
	ll mxff = -1, mnff = inf;
	ll n, tr= 0;
	cin >> n;
	for(ll i =0;i<n;i++){
		cin >> a[i];
		if(i > 0){
			if(a[i] == -1){
				if(a[i-1] != -1) mxff = max(mxff, a[i-1]), mnff = min(mnff, a[i-1]);
			}else{
				if(a[i-1] == -1)  mxff = max(mxff, a[i]), mnff = min(mnff, a[i]);
				else tr = max(tr, abs(a[i]-a[i-1]));
			}
		}
	}
	if(mxff == -1){
		cout << "0 0\n";
	}else{
		ll opt = (mxff+mnff)/2;
		cout << max(tr, mxff-opt) << " " << opt << '\n';
	}
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}