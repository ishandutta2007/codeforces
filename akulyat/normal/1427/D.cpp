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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
vector<vector<ll>> ans;
bool viv = false;

void cut(vector<ll> sz) {
	vector<vector<ll>> gg;
	ans.push_back({});
	for (int i = 1; i < sz.size(); i++) {
		gg.push_back({});
		ans.back().push_back(sz[i] - sz[i - 1]);
		for (int j = sz[i - 1]; j < sz[i]; j++)
			gg.back().push_back(v[j]);
	}
	reverse(gg.begin(), gg.end());
	vector<ll> nv;
	for (auto &l : gg)
		for (auto i : l)
			nv.push_back(i);
	if (viv) {
		cout << "cut by ";
		for (auto i : sz)
			cout << i << ' ';
		cout << endl;
		cout << "was ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
		cout << "see ";
		for (auto i : nv)
			cout << i << ' ';
		cout << endl;
	}
	v = nv;
}

void maker(ll a, ll b) {
	ll c = n;
	vector<ll> cc;
	cc.push_back(0);
	cc.push_back(a);
	cc.push_back(b);
	if (b != n)
		cc.push_back(c);
	cut(cc);
}

void show() {
	cout << ans.size() << endl;
	for (auto l : ans) {
		cout << l.size() << ' ';
		for (auto i : l)
			cout << i << ' ';
		cout << endl;
	}
	if (viv) {
		cout << "\t SEE:";
		for (auto i : v)
			cout << i << ' ';
	}
	exit(0);	
}

void fin() {
	if (v[0] != 0) {
		ll pl = 0;
		while (v[pl] != 0)
			pl++;
		cut({0, pl, n});
	}
	show();
}

void work() {
	ll l = 0;
	ll r = 1;
	while (r < n && v[r] == (v[r - 1] + 1) % n)
		r++;
	if (r == n)
		fin();
	ll val = v[0];
	ll need = (val + n - 1) % n;

	ll nr = 0;
	while (v[nr] != need)
		nr++;
	ll nl = nr - 1;
	while (nl != -1 && (v[nl] + 1) % n == v[nl + 1])
		nl--;

	if (viv) {
		cout << "l, r = " << l << ' ' << r << endl;
		cout << "nl, nr = " << nl << ' ' << nr << endl;
	}

	maker(nl + 1, nr + 1);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	for (int i = 0; i < n; i++)
		work();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}