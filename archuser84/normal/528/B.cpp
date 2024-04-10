#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second 
#define pb push_back
#define mk make_pair
#define endl cout << '\n'
#define haha cerr << "haha\n"
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
ll const inf = 1'000'000'000'000'000;
ll const mod = 1'000'000'007;
ll const maxn = 100'000 + 10;
ll const lg = 19;
ll const sq = 300;
ll const base = 337;
vector <pll> vec;

void Main() {
	ll n;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		ll x, w;
		cin >> x >> w;
		vec.pb(mk(x + w, x - w));
	}
	ll pleh = -inf;
	ll ans = 0;
	sort(vec.begin(), vec.end());
	for (ll i = 0; i < n; ++i) {
		if (vec[i].S >= pleh) {
			++ans;
			pleh = vec[i].F;
		}
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--) {
		Main();
	}
	return 0;
}