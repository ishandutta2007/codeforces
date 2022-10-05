#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 

ll n, m;
vector<ll> v;
vector<ll> pr, obr;
vector<pll> def;
bool viv = false;

ll sum(ll l, ll r) {
	r++;
	return pr[r] - pr[l];
}

ll obrr(ll v, ll st = mod - 2) {
	if (st == 0)
		return 1;
	ll val = obrr(v, st / 2);
	ll res = val * val;
	res %= mod;
	if (st & 1)
		res *= v;
	res %= mod;
	return res;
}

void prepare() {
	obr.push_back(1);
	for (int i = 1; i < 2 * n + 10; i++)
		obr.push_back(obrr(i));
}

ll get(ll x, ll y) {
	ll res = 1;

	res *= x;
	res *= obr[y];
	res %= mod;
	return res;
}

void solve() {
	cin >> n >> m;
	prepare();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	pr.push_back(0);
	for (auto i : v)
		pr.push_back(pr.back() + i);

	def.resize(m);
	for (int i = 0; i < m; i++) {
		ll ans = 0;
		ll a, b;
		cin >> a >> b;
		if (viv)
			cout << "read " << a << ' ' << b << endl; 
		ll easy = lower_bound(v.begin(), v.end(), b) - v.begin();
		ll hard = n - easy;
		if (viv)
			cout << "see: " << easy << ' ' << hard << endl;
		if (hard >= a) {
			ll s = sum(0, easy - 1);
			s %= mod;
			if (viv)
				cout << "Easy sum = " << s << endl;
			ll x = get((hard + 1 - a), (hard + 1));

			ans += s * x;
			ans %= mod;
		}
		if (hard > a) {
			ll s = sum(easy, n - 1);
			s %= mod;
			if (viv)
				cout << "Hard sum = " << s << endl;
			ll x = get((hard - a), (hard));

			ans += s * x;
			ans %= mod;
		}

		cout << ans << '\n';
		if (viv)
			cout << endl;
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}