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

ll n, m;
vector<vector<ll>> v;
vector<vector<ll>> l, r, ans, d, u;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.resize(n);
	if (viv)
		cout << "OK" << endl;

	for (auto &l : v) {
		string s;
		cin >> s;
		for (auto i : s)
			l.push_back(i - 'a');
	}

	if (viv)
		cout << "OK" << endl;


	l.resize(n, vector<ll>(m, 1));
	r.resize(n, vector<ll>(m, 1));
	d.resize(n, vector<ll>(m, 1));
	u.resize(n, vector<ll>(m, 1));
	ans.resize(n, vector<ll>(m, 1));

	if (viv)
		cout << "OK" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (v[i][j] == v[i][j - 1])
				l[i][j] += l[i][j - 1];
		}
		for (int j = m - 2; j >= 0; j--) {
			if (v[i][j] == v[i][j + 1])
				r[i][j] += r[i][j + 1];
		}
	}

	if (viv)
		cout << "OK" << endl;

	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			if (v[i][j] == v[i - 1][j])
				u[i][j] = min(u[i - 1][j] + 1, min(l[i][j], r[i][j]));
		}
		for (int i = n - 2; i >= 0; i--) {
			if (v[i][j] == v[i + 1][j])
				d[i][j] = min(d[i + 1][j] + 1, min(l[i][j], r[i][j]));
		}
	}

	if (viv)
		cout << "OK" << endl;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			ans[i][j] = min(d[i][j], u[i][j]);
	} 

	ll res = 0;

	for (auto l : ans)
		for (auto i : l)
			res += i;

	cout << res << '\n';

	if (viv) {
		cout << "r\n";
		for (auto ln : r) {
			for (auto i : ln)
				cout << i << ' ';
			cout << endl;
		}
		cout << "l\n";
		for (auto ln : l) {
			for (auto i : ln)
				cout << i << ' ';
			cout << endl;
		}
		cout << "d\n";
		for (auto ln : d) {
			for (auto i : ln)
				cout << i << ' ';
			cout << endl;
		}
		cout << "u\n";
		for (auto ln : u) {
			for (auto i : ln)
				cout << i << ' ';
			cout << endl;
		}
		cout << "ans\n";
		for (auto ln : ans) {
			for (auto i : ln)
				cout << i << ' ';
			cout << endl;
		}
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