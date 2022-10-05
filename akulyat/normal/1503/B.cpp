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
vector<vector<int>> v;
vector<pii> d[2];
bool viv = false;

int getc() {
	int col;
	cin >> col;
	return col - 1;
}

void put(int c, pii pl) {
	cout << c + 1 << ' ';
	cout << pl.F + 1 << ' ' << pl.S + 1 << endl;
	v[pl.F][pl.S] = c;
}

void move() {
	int c = getc();
	if (d[0].size() && d[1].size()) {
		int mc = 0;
		if (mc == c)
			mc = 1;

		auto pr = d[mc].back();
		put(mc, pr);
		d[mc].pop_back();
	} else {
		int pc = 0;
		if (d[pc].empty())
			pc++;
		int mc = pc;
		if (c == mc)
			mc = 2;

		auto pr = d[pc].back();
		put(mc, pr);
		d[pc].pop_back();
	}
}

void solve() {
	cin >> n;
	v.resize(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[(i + j) & 1].push_back({i, j});
		}
	}
	for (int i = 0; i < n * n; i++) {
		move();
	}

	if (viv) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << v[i][j];
			cout << endl;
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