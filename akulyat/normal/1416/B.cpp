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
ll val;
vector<ll> v;
vector<pll> ord;
vector<vector<ll>> ans;
bool viv = false;

void make(ll i, ll j, ll x) {
	if (x == 0)
		return;
	assert(x > 0);

	if (viv) {
		cout << "bef = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	ans.push_back({i + 1, j + 1, x});
	v[i] -= x * (i + 1);
	v[j] += x * (i + 1);	
	if (viv) {
		cout << "aft = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
		cout << endl;
	}
}

void up(int i) {
	int j = i + 1;
	j %= n;
	ll x = v[i] / (i + 1);
	make(i, j, x);
}

void change(ll pl, bool work) {
	if (viv)
		cout << "change(" << pl << ")" << endl;	
	ll need = val;
	while (need < v[pl])
		need += pl + 1;
	if (!work) {
		ord.push_back({val - v[pl], pl});
		return;
	}
	make(0, pl, need - v[pl]);

	ll x = v[pl] - val;
	x /= (pl + 1);
	make(pl, 0, x);
}

void show() {
	if (viv) {
		cout << "See " << val << ": ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}	
}

bool bad() {
	for (int i = 1; i < n; i++)
		if (v[i] != v[i - 1]) {
			assert(false);
			return true;
		}
	return false;
}

void solve() {
	cin >> n;
	v.clear();
	ans.clear();
	ord.clear();
	v.resize(n);

	ll s = 0;
	for (auto &i : v)
		cin >> i, s += i;
	if (s % n) {
		cout << -1 << '\n';
		return;
	}

	val = s / n;
	for (int i = 0; i < n; i++)
		up(i);
	for (int i = 1; i < n; i++)
		change(i, false);
	sort(ord.begin(), ord.end());
	if (viv)
		for (auto p : ord)
			cout << "____" << p.F << ' ' << p.S << endl;
	for (int i = 1; i < n; i++)
		change(ord[i - 1].S, true);

	if (bad()) {
		cout << "-1\n";
		return;
	}

	cout << ans.size() << '\n';
	for (auto l : ans) {
		for (auto i : l)
			cout << i << ' ';
		cout << '\n';
	}
	show();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}