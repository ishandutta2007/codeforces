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

int n;
vector<int> v;
vector<bool> side;
bool viv = false;

void bad_day() {
	cout << "-1\n";
	exit(0);	
}

void solve() {
	cin >> n;
	v.resize(n);
	side.resize(n, false);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a >= n && b >= n) {
			bad_day();
		}
		int mn = min(a, b);
		int mx = max(a, b);
		v[mn] = mx;
		side[mn] = (a == mn);
	}
	if (viv) {
		cout << "v = ";
		for (auto i : v) 
			cout << i << ' ';
		cout << endl;
		cout << "side = ";
		for (auto i : side) 
			cout << i << ' ';
		cout << endl;
	}
	int cur_min = mod;
	vector<int> block(1, 0);
	for (int i = 0; i < n; i++) {
		block.back()++;
		cur_min = min(cur_min, v[i]);
		if (cur_min == 2 * n - 1 - i) 
			block.push_back(0);
	}
	if (viv) {
		cout << "block = ";
		for (auto i : block)
			cout << i << ' ';
		cout << endl;
	}
	int l = 0;
	int ans = 0;
	for (auto len : block) {
		int r = l + len;
		pii mn = {mod, mod};
		int bad = 0;
		for (int i = l; i < r; i++) {
			if (viv)
				cout << "\tsee: " << mn.F << ' ' << mn.S << endl;
			if (abs(mn.F - v[i]) < abs(mn.S - v[i]) && v[i] < mn.F || mn.S < v[i]) {
				if (v[i] > mn.F)
					bad_day();
				mn.F = v[i];
				bad += side[i];
			} else {
				if (v[i] > mn.S)
					bad_day();
				mn.S = v[i];
				bad += !side[i];
			}
		}
		ans += min(bad, r - l - bad);
		l = r;
	}

	cout << ans << '\n';
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