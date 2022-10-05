#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

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
vector<vector<ll>> f;

void bad() {
	if (n == 3) {
		vector<vector<ll>> v = {
								{9, 1, 5},
								{6, 2, 3},
								{7, 8, 4}
							   };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << v[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	cout << -1;
	exit(0);
}

void solve() {
	cin >> n;
	if (n <= 3)
		bad();
	f.resize(n);
	for (auto &l : f)
		l.resize(n, -1);
	vector<vector<ll>> v = {
							{4, 3, 6, 12},
							{7, 5, 9, 15},
							{14, 1, 11, 10},
							{13, 8, 16, 2}
						   };

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			f[i][j] = v[i][j] + (n * n - 16);
	set<pll> s;
	int cf = 1;
	if (n & 1)
		cf = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {			
			if (max(i, j) > 3)
				s.insert({i, j * cf});
		}
		cf *= -1;
	}

	vector<pll> vv;
	for (auto i : s)
		vv.push_back(i);
	if (vv.size()) {
		swap(vv[vv.size() - 1], vv[vv.size() - 2]);
		if (!(n & 1)) {
			swap(vv[vv.size() - (n - 4) * n], vv[vv.size() - (n - 4) * n + 4]);
		}
	}

	if (viv) {
		for (auto p : vv)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
	}

	ll now = 1;
	for (auto i : vv)
		f[i.F][abs(i.S)] = now, now++;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << f[i][j] << ' ';
		cout << '\n';
	}
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}