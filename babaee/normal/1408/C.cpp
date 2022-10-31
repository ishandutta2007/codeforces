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

ll solve() {
	ll n, l;
	cin >> n >> l;
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	ld f1 = 0, f2 = n - 1, s1 = 1, s2 = 1, rem1 = v[0], rem2 = l - v.back(), ans = 0, pos1 = 0, pos2 = l;
	while (true) {
		if (f1 > f2) {
			ans += min(rem1, rem2) / (s1 + s2);
			break;
		}
		
		ld t1 = rem1 / s1, t2 = rem2 / s2;
		if (t1 == t2 && f1 == f2) {
			ans += t1;
			break;
		}

		if (t1 < t2) {
			rem1 = 0;
			f1++;
			ans += t1;
			pos1 += s1 * t1;
			pos2 -= s2 * t1;
			s1++;
			rem2 -= s2 * t1;
		} else if (t1 == t2) {
			rem1 = 0;
			rem2 = 0;
			f1++;
			f2--;
			pos1 += s1 * t1;
			pos2 -= s2 * t1;
			s1++;
			s2++;
			ans += t1;
		} else {	
			pos1 += s1 * t2;
			pos2 -= s2 * t2;
			rem2 = 0;
			f2--;
			ans += t2;
			s2++;
			rem1 -= s1 * t2;
		}
		
		if (f1 == n || f2 < 0) {
			ans += (pos2 - pos1) / (s1 + s2);
			break;
		}

		rem1 = v[f1] - pos1;
		rem2 = pos2 - v[f2];
	}
	
	cout << setprecision(15) << fixed ;
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