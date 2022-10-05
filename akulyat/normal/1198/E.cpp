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

ll n, l;
bool viv = false;
vector<pll> x, y;
set<ll> sx, sy;
vector<pll> segx, segy;
vector<pll> usex, usey;

void build(ll &n, ll &m, vector<unordered_map<ll, pll>> &e) {
	n = segx.size() + segy.size() + 2;
	e.resize(n);
	for (int i = 0; i < x.size(); i++) {
		for (int l = usex[i].F; l < usex[i].S; l++) {
			for (int r = usey[i].F; r < usey[i].S; r++) {
				if (viv)
					cout << i << ' ' << l << ' ' << r << endl;
				e[1 + l][1 + segx.size() + r] = {0, mod}, m++;
			}
		}
	}
	for (int i = 0; i < segx.size(); i++) {
		e[0][1 + i] = {0, segx[i].S - segx[i].F}, m++;
	}
	for (int i = 0; i < segy.size(); i++) {
		e[1 + segx.size() + i][n - 1] = {0, segy[i].S - segy[i].F}, m++;
	}

	if (viv) { 
		cout << n << ' ' << m << endl;
		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			for (auto p : e[i])
				cout << p.F << ' ' << p.S.S << "; ";
			cout << endl;
		}
	}
}

void BFS(ll n, ll s, ll t, bool &cont, ll &fl, vector<unordered_map<ll, pll>> &e) {
	vector<ll> d, p;
	d.resize(n, mod);
	p.resize(n, -1);
	d[s] = 0;
	p[s] = s;
	vector<ll> dq;
	dq.push_back(s);
	ll st = 0;
	while (st != dq.size()) {
		ll v = dq[st];
		st++;
		for (auto it : e[v]) {
			ll s = it.F, f = it.S.F, c = it.S.S;
			if (f != c && d[s] > d[v] + 1) {
				d[s] = d[v] + 1;
				p[s] = v;
				dq.push_back(s);
			}
		}
	}
	if (viv) {
		cout << "Par: ";
		for (auto i : p)
			cout << i << ' ';
		cout << endl;
	}

	if (d[t] == mod) {
		cont = false;
		return;
	}

	vector<ll> path;
	path.push_back(t);
	while (path.back() != s)
		path.push_back(p[path.back()]);
	reverse(path.begin(), path.end());
	if (viv) {
		cout << "Path: ";
		for (auto i : path)
			cout << i << ' ';
		cout << endl;
	}

	ll delt = mod;
	for (int i = 1; i < path.size(); i++) {
		ll v2 = path[i];
		ll v1 = p[v2];
		delt = min(delt, e[v1][v2].S - e[v1][v2].F);
	}
	if (viv) {
		cout << "Add " << delt << '\n';
	}
	if (delt == 0) {
		cont = false;
		return;		
	}


	fl += delt;
	for (int i = 1; i < path.size(); i++) {
		ll v2 = path[i];
		ll v1 = p[v2];
		e[v1][v2].F += delt;
		e[v2][v1].F -= delt;
	}
}

ll flow() {
	ll n = 0, m = 0;
	vector<unordered_map<ll, pll>> e;
	build(n, m, e);
	ll s = 0;
	ll t = n - 1;
	ll fl = 0;


	for (int v = 0; v < n; v++) {
		for (auto it : e[v]) {
			if (e[it.F].find(v) == e[it.F].end())
				e[it.F][v] = {0, 0};
		}
	}
	bool cont = true;
	while (cont)
		BFS(n, s, t, cont, fl, e);
	return fl;
}


void solve() {
	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--;
		x.push_back({x1, x2});
		y.push_back({y1, y2});
		sx.insert(x1);
		sx.insert(x2);
		sy.insert(y1);
		sy.insert(y2);
	}
	sx.insert(0);
	sx.insert(l);
	sy.insert(0);
	sy.insert(l);
	if (viv) {
		cout << "sx: ";
		for (auto i : sx)
			cout << i << ' ';
		cout << endl;
	}

	while (sx.size() > 1) {
		ll l = *sx.begin();
		sx.erase(sx.begin());
		ll r = *sx.begin();
		segx.push_back({l, r});
	}
	while (sy.size() > 1) {
		ll l = *sy.begin();
		sy.erase(sy.begin());
		ll r = *sy.begin();
		segy.push_back({l, r});
	}

	for (int i = 0; i < n; i++) {
		ll lx = mod, rx = -mod;
		for (int j = 0; j < segx.size(); j++) {
			if (x[i].F <= segx[j].F && segx[j].S <= x[i].S)
				lx = min(lx, (ll)j), rx = max(rx, (ll)j);
		}
		rx++;
		ll ly = mod, ry = -mod;
		for (int j = 0; j < segy.size(); j++) {
			if (y[i].F <= segy[j].F && segy[j].S <= y[i].S)
				ly = min(ly, (ll)j), ry = max(ry, (ll)j);
		}		
		ry++;
		usex.push_back({lx, rx});
		usey.push_back({ly, ry});
	}
	if (viv) {
		for (auto i : segx) {
			cout << "segx: ";
			cout << i.F << ' ' << i.S << "; ";
			cout << endl;
		}
		for (auto i : segy) {
			cout << "segy: ";
			cout << i.F << ' ' << i.S << "; ";
			cout << endl;
		}
		for (auto i : usex) {
			cout << "usex: ";
			cout << i.F << ' ' << i.S << "; ";
			cout << endl;
		}
		for (auto i : usey) {
			cout << "usey: ";
			cout << i.F << ' ' << i.S << "; ";
			cout << endl;
		}
	}
	ll ans = flow();
	cout << ans << endl;
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}