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
vector<pll> v;
vector<vector<pll>> e;
bool viv = false;


void solve() {
	n = 22;	
	v.resize(n, {0, 0});
	e.resize(n);
	for (int i = 1; i < n - 1; i++) {
		e[0].push_back({i, 1});
		int len = 1;
		for (int j = i - 1; j > 0; j--) {
			if (viv)
				cout << i << " Add " << len + v[j].F << ' ' << len + v[j].S << '\n';
			e[j].push_back({i, len});
			len += (v[j].S - v[j].F + 1);
		}
		v[i] = {1, {1 << (i - 1)}};
		if (viv)
			cout << "\t" << i << " see " << v[i].F << ' ' << v[i].S << '\n';
	}
	int L, R;
	cin >> L >> R;
	v[n - 1] = {L, R};
	if (L == 1) {
		e[0].push_back({n - 1, 1});
		L++;
	}
	for (int j = n - 2; j > 0; j--) {
		int len = v[j].S - v[j].F + 1;
		if (R - L + 1 >= len) {
			e[j].push_back({n - 1, L - 1});
			L += len;
		}
	}

	if (viv)
		cout << "see " << L << ' ' << R << '\n';

	cout << "YES\n";
	int m = 0;
	for (auto l : e)
		m += l.size();
	cout << n << ' ' << m << '\n';
	for (int i = 0; i < n; i++) {
		int v = i;
		for (auto p : e[v]) {
			int u = p.F;
			int l = p.S;
			if (viv && u == n - 1)
				cout << "\t";
			cout << v + 1 << ' ';
			cout << u + 1 << ' ';
			cout << l << '\n';
		}
	}
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