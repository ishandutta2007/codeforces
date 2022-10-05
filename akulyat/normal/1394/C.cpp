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
const int C = 35;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<string> v;
vector<pii> p;
pii prevv;
int cf = 1;
bool viv = false;

int dist(int x1, int y1, int x2, int y2) {
	bool dif = x1 < x2 && y1 > y2 || x1 > x2 && y1 < y2;
	if (dif)
		return abs(x1 - x2) + abs(y1 - y2);
	return max(abs(x1 - x2), abs(y1 - y2));
}

int get(int x, int y) {
	if (x < 0 || y < 0)
		return mod;
	if (x == 0 && y == 0)
		return mod;
	int res = 0;
	for (auto pr : p)
		res = max(res, dist(pr.F, pr.S, x, y));
	return res;
}

int get(pii p) {
	return get(p.F, p.S);
}

bool find(int r, bool out = false) {
	int lx, rx, ly, ry, ldif, rdif;
	lx = 0, rx = mod;
	ly = 0, ry = mod;
	ldif = -mod, rdif = mod;
	for (auto pr : p) {
		lx = max(lx, pr.F - r);
		rx = min(rx, pr.F + r);
		ly = max(ly, pr.S - r);
		ry = min(ry, pr.S + r);
		ldif = max(ldif, pr.F - pr.S - r);
		rdif = min(rdif, pr.F - pr.S + r);
	}
	if (viv) {
		cout << r << ": \n";
		cout << "\t x = " << lx << ' ' << rx << '\n';
		cout << "\t y = " << ly << ' ' << ry << '\n';
		cout << "\t dif = " << ldif << ' ' << rdif << endl;

	}
	if (lx > rx || ly > ry || ldif > rdif)
		return false;

	pii p = {rx, ly};
	while (p.F > lx && p.F - p.S > rdif)
		p.F--;
	while (p.S < ry && p.F - p.S > rdif)
		p.S++;
	if (p.F - p.S > rdif || p.F - p.S < ldif)
		return false;

	if (out) {
		if (p.F == 0 && p.S == 0) {
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					if (i != 0 || j != 0)
						if (get(i, j) == r)
							p = {i, j};
		}		

		cout << r << '\n';
		for (int i = 0; i < p.F; i++)
			cout << 'B';
		for (int i = 0; i < p.S; i++)
			cout << 'N';
		cout << endl;

		assert(get(p.F, p.S) == r);
		exit(0);
	}

	return true;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &s : v) {
		cin >> s;
		pii cnt = {0, 0};
		for (auto i : s) {
			cnt.F += (i == 'B');
			cnt.S += (i == 'N');
		}
		p.push_back(cnt);
	}
	int l = -1;
	int r = ml * 5;
	while (l + 1 < r) {
		int m = l + r >> 1;
		if (find(m))
			r = m;
		else
			l = m;
	}

	find(r, true);
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