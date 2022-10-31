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
ll b[N], bts[N];
bool es[N];

python solve(){
	FAST;
	cin >> n;
	for(ll a, i =0;i<n;i++){
		cin >> a;
		b[a]++;
	}
	ll xc = 0;
	for(ll i = 1;i<=n;i++) if(b[i]) xc++;
	ll mv = 0, mxv = 0;
	for(ll i = 1;i<=n;i++){
		if(b[i] == 0) continue;
		++mv, i+=2;
		bts[i] = b[i]+bts[i-1];
	}
	ll bxt = 0, bxs = 0;
	for(ll i = 1;i<=n+1;i++){
		if(b[i]) ++bxt, bxs+=b[i];
		else{
			if(bxs-bxt == 1){
				if(es[i-bxt-1]){
					es[i] = 1;
					++mxv;
				}else{
					es[i-bxt-1] = 1;
					++mxv;
				}
			}else if(bxs-bxt>=2){
				es[i] = 1;
				++mxv;
				if(!es[i-bxt-1]){
					es[i-bxt-1] = 1;
					++mxv;
				}
			}
			bxt= 0, bxs = 0;
		}
	}
	cout << mv << ' ' << mxv+xc << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}