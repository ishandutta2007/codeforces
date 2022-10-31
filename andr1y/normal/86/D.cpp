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
const ll C = 450;
const ll W = 6;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll cnt[1000100];
ll a[N], ans[N];
struct query{
	ll l, r, real;
};
vector<query> b[C+W];

python solve(){
	FAST;
	ll n, q;
	cin >> n >> q;
	for(ll i =0;i<n;i++) cin >> a[i];
	for(ll l, r, i =0;i<q;i++){
		cin >> l >> r;
		--l, r--;
		query qsx;
		qsx.l = l, qsx.r = r, qsx.real = i;
		b[l/C].pb(qsx);
	}
	for(ll i =0;i<C+W;i++){
		if(b[i].size() == 0) continue;
		sort(itr(b[i]), [](query a, query b){
			return a.r < b.r;
		});
		ll l = b[i][0].l, r = b[i][0].r, res = 0;
		for(ll j = l;j<=r;j++){
			res -= cnt[a[j]]*cnt[a[j]]*a[j];
			cnt[a[j]]++;
			res += cnt[a[j]]*cnt[a[j]]*a[j];
		}
		ans[b[i][0].real] = res;
		for(ll unusd = 1;unusd<b[i].size();unusd++){
			query now = b[i][unusd];
			while(r < now.r){
				++r;
				res -= cnt[a[r]]*cnt[a[r]]*a[r];
				cnt[a[r]]++;
				res += cnt[a[r]]*cnt[a[r]]*a[r];
			}
			while(l < now.l){
				res -= cnt[a[l]]*cnt[a[l]]*a[l];
				cnt[a[l]]--;
				res += cnt[a[l]]*cnt[a[l]]*a[l];
				++l;
			}
			while(l > now.l){
				--l;
				res -= cnt[a[l]]*cnt[a[l]]*a[l];
				cnt[a[l]]++;
				res += cnt[a[l]]*cnt[a[l]]*a[l];
			}
			ans[now.real] = res;
		}
		while(l <= r){
			cnt[a[l++]]--;
		}
	}
	for(ll i =0;i<q;i++) cout << ans[i] << '\x0a';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}