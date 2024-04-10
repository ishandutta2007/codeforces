#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a, b, c, d;

ll val(ll n) {
	ll ans = n * a;
	ll time = n * d - d;
	ll full = (time - c) / d, F, rem;
	if (time >= c) full++;
	if (full > 0) {
	
		rem = n - full;;
		ans -= full * b * c;
		if (rem <= 0) return ans;
		F = time - full * d;
	} else {
		rem = n;
		F = time;	
	}
	ans -= max(0ll, (rem) * (F) * b / 2);
	return ans;
}

ll solve() {
	cin >> a >> b >> c >> d;
	if (c <= d) {
		if (b * c < a) return cout << -1 << endl, 0;
		else return cout << a << endl, 0;
	}


	if (c * b < a) return cout << -1 << endl, 0;
	
	ll L = 0, R = ll(1e7);
	while (L < R - 100) {
		ll mid1 = L + (R - L) / 3, mid2 = R - (R - L) / 3;
		if (val(mid1) > val(mid2)) R = mid2;
		else L = mid1;
	}	
	
	ll ans = 0;
	while (L <= R) {
		ans = max(ans, val(L));
		L++;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}