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
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<ll> v;
bool viv = false;

void work(ll n) {
	vector<vector<ll>> v(n, vector<ll>(n));
	ll si = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ll d = (i + j);
			ll val = 0;
			if (d > 0)
				val = (1ll << (d - 1));
			v[i][j] = val * (i & 1);
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	return;
	ll s = 2 * (n - 1);
	set<ll> vals;
	ll was = 0;
	for (int m = 0; m < (1 << s); m++) {
		vector<ll> go;
		ll f = m;
		for (int j = 0; j < s; j++)
			go.push_back(f & 1), f >>= 1;
		ll cnt = 0;
		for (auto i : go)
			cnt += i;
		if (2 * cnt == s) {
			ll res = 0;
			ll x = 0, y = 0;
			res += v[x][y];
			for (int i = 0; i < s; i++) {
				x += go[i];
				y += 1 - go[i];
				assert(x < n);
				assert(y < n);
				res += v[x][y];
			}
			vals.insert(res);
			was++;
		}
	}
	cout << was << ' ' << vals.size() << '\n';
}

void h() {
	ll val;
	cin >> val;
	ll x = 0, y = 0;
	cout << x + 1 << ' ' << y + 1 << '\n';
	bool last = false;
	for (int i = 0; i < 2 * n - 2; i++) {
		// cout << "see " << val << ' ' << i << endl;
		if (((val & 1) ^ (x & 1)) && x < n - 1 || y == n - 1)
			x++, last = true;
		else
			y++, last = false;
		val >>= 1;
		cout << x + 1 << ' ' << y + 1 << endl;
	} 
	cout << endl;
}

void solve() {
	// for (int i = 2; i < 11; i++)
	// 	work(i);
	// return;
	cin >> n;
	work(n);
	ll q;
	cin >> q;
	while (q--)
		h();
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