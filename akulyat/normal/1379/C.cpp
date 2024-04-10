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


void solve() {
	ll n, m;
	vector<ll> a, b;
	cin >> n >> m;
	a.resize(m);
	b.resize(m);
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i];

	vector<ll> f, p;
	f = a;
	sort(f.rbegin(), f.rend());

	p.push_back(0);
	for (auto i : f)
		p.push_back(p.back() + i);
	if (viv) {
 		for (auto i : p)
			cout << i << ' ';
		cout << endl;
	}

	ll ans = 0;
	for (int i = 0; i < m; i++) {
		ll lans = 0;
		ll have = n;

		ll l = -1;
		ll r = m;
		while (l + 1 < r) {
			ll mi = l + r >> 1;
			if (f[mi] > b[i])
				l = mi;
			else
				r = mi;
		}
		l = min(l, have - 1);
		if (l == -1 || f[l] > a[i]) {
			if (l + 1 == have)
				l--, have--;
			else
				have--;
			lans += a[i];
		}

		if (viv)
			cout << "use " << l + 1 << " best" << endl;

		lans += p[l + 1];
		have -= (l + 1);

		if (viv)
			cout << "add " << b[i] << " " << have << " times" << endl;
		lans += have * b[i];

		ans = max(ans, lans);

		if (viv)
			cout << "with " << i << " see: " << lans << endl << endl;
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}