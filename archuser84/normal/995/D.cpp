#include <bits/stdc++.h>
 
using namespace std;

#define F first
#define S second 
#define pb push_back
#define mk make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
ll const inf = 1'000'000'000'000'000;
ll const mod = 1'000'000'007;
ll const maxn = 20;
vector <ll> v;


int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cout << setprecision(10) << fixed;
	ll n, r;
	cin >> n >> r;
	ll ans = 0;
	for (ll i = 0; i < (1 << n); ++i) {
		ll x;
		cin >> x;
		v.pb(x);
		ans += x;
	}
	ll pleh = (1 << n);
	cout << ans / ld(pleh) << '\n';
	while (r--) {
		ll a, b;
		cin >> a >> b;
		ans -= v[a];
		v[a] = b;
		ans += v[a];
		cout << ans / (ld)pleh << '\n';
		
	}
	return 0;
}