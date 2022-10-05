#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
bool viv = false;
vector<ll> v;

ll get_nx(vector<vector<ll>> &v, vector<bool> &used) {
	vector<ll> cnt1, cnt2;
	cnt1.resize(n);
	cnt2.resize(n);
	for (int i = 0; i < n - 1; i++) {
		for (auto val : v[i]) {
			cnt2[val]++;
			if (!used[i])
				cnt1[val]++;
		}
	}
	set<pair<pll, ll>> s;
	for (int i = 0; i < n; i++)
		s.insert({{cnt1[i], -cnt2[i]}, i});
	if (viv) {
		for (auto p : s) {
			cout << "\t" << p.S << ' ' << p.F.F << ' ' << p.F.S << endl;
		}

	}
	while ((*s.begin()).F.F == 0)
		s.erase(s.begin());
	ll res = (*s.begin()).S;
	if (viv) {
		cout << "Add " << res << endl; 
	}
	return res;
}

void eraser(vector<vector<ll>> &v, vector<bool> &used, ll val) {
	for (int i = 0; i < n - 1; i++) {
		for (auto j : v[i])
			if (j == val)
				used[i] = true;
	}
}

bool check(vector<vector<ll>> &v, vector<ll> &res) {
	vector<ll> o(n, -1);
	for (int i = 0; i < n; i++)
		o[res[i]] = i;
	for (auto vec : v) {
		ll mx = -1, mn = n + 1;
		for (auto p : vec) {
			mx = max(mx, o[p]);
			mn = min(mn, o[p]);
		}
		if (mx - mn + 1 != vec.size())
			return false;
	}
	return true;
}


bool can(vector<vector<ll>> &v, vector<ll> &cnt, ll f) {
	if (cnt[f] > 1)
		return false;
	if (viv) {
		cout << "Start with " << f << endl;
	}
	vector<ll> res;

	ll nx = f;
	vector<bool> used(n - 1, false);
	for (ll i = 0; i < n - 1; i++) {
		res.push_back(nx);
		eraser(v, used, nx);
		if (i + 1 != n - 1)
			nx = get_nx(v, used);
	}
	ll star = (n * (n - 1)) / 2;
	for (auto i : res)
		star -= i;
	res.push_back(star);

	reverse(res.begin(), res.end());
	if (!check(v, res))
		return false;

	for (auto &i : res)
		i++;
	for (auto i : res)
		cout << i << ' ';
	cout << '\n';
	return true;
}

void solve() {
	if (viv) {
		cout << endl;
		cout << "Test case" << endl;
	}

	cin >> n;

	vector<vector<ll>> v;
	vector<ll> cnt;
	v.resize(n - 1);
	cnt.resize(n);
	for (int i = 0; i < n - 1; i++) {
		ll k;
		cin >> k;
		v[i].resize(k);
		for (auto &j : v[i])
			cin >> j, j--, cnt[j]++;
	}

	for (int i = 0; i < n; i++) {
		if (can(v, cnt, i))
			return;
	}
	assert(1 == 0);
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