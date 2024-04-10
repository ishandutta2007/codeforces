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
const ll N = 2228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[N][N];
ll a[N], sa[N];
python solve(){
	FAST;
	ll n, h, l, r;
	cin >> n >> h >> l >> r;
	for(ll i = 0;i<n;i++) cin >> a[i];
	sa[0] = a[0];
	for(ll i = 1;i<n;i++) sa[i] = sa[i-1]+a[i];
	dp[0][0] = (l<=a[0]&&a[0]<=r);
	dp[0][1] = (l<=a[0]-1&&a[0]-1<=r);
	for(ll i = 1;i<n;i++){
		for(ll skip = 1;skip<=i;skip++){
			ll hrs = (sa[i]-skip)%h;
			dp[i][skip] = max(dp[i-1][skip-1], dp[i-1][skip]);
			dp[i][skip] += (l<=hrs&&hrs<=r);
		}
		ll hrs = sa[i]%h;
		dp[i][0] = dp[i-1][0]+(l<=hrs&&hrs<=r);
		hrs = (sa[i]-i-1)%h;
		dp[i][i+1] = dp[i-1][i]+(l<=hrs&&hrs<=r);
	}
	ll ans  =0;
	for(ll i = 0;i<=n;i++) ans = max(dp[n-1][i], ans);
		cout << ans << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}