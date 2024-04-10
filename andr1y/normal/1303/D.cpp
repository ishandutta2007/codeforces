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
ll cnt[64];
ll fre[64];
python solve(){
	FAST;
	ll s, n;
	memset(cnt, 0, sizeof(cnt));
	memset(fre, 0, sizeof(fre));
	cin >> s >> n;
	for(ll a, i = 0 ;i<n;i++){
		ll c  = 0;
		cin >> a;
		while(a) ++c, a>>=1;
		--c;
		cnt[c]++;
	}
	for(ll i  =0;i<64;i++){
		fre[i] = cnt[i]>>1;
		cnt[i+1] += cnt[i]>>1;
		cnt[i] &= 1;
	}
	bool ok = 1;
	ll rs = 0;
	for(ll i = 60;i>=0;i--){
		if((s>>i)&1){
			ll fnd = -1;
			for(ll j = i;j<64;j++){
				if(cnt[j]){
					fnd = j;
					break;
				}
			}
			if(fnd == -1){
				ok = 0;
				break;
			}
			ll cost = 0;
			cnt[fnd]--;
			for(ll j = fnd-1;j>=i;j--){
				if(fre[j] == 0){
					cost++;
				}else{
					fre[j]--;
				}
				cnt[j]++;
			}
			rs+=cost;
		}
	}
	if(ok) cout << rs << '\n';
	else cout << "-1\n";
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}