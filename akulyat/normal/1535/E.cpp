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

const int K = 19;

ll q;
vector<int> p, d;
vector<vector<int>> pp;
vector<pll> vec;
bool viv = false;

void add(int pr, int a, int c, int v) {
	vec.push_back({a, c});
	if (v) {
		d.push_back(d[pr] + 1);
		p.push_back(pr);
		pp[0].push_back(pr);
		for (int i = 1; i < K; i++)
			pp[i].push_back(pp[i - 1][pp[i - 1][v]]);
	}
}

int LA(int v, int up) {
	if (viv)
		cout << "\t\tLA(" << v << ' ' << up << ")" << endl;
	if (up <= 0)
		return v;
	for (int i = K - 1; i >= 0; i--)
		if (up >= (1 << i)) {
			up -= (1 << i);
			v = pp[i][v];
		}
	if (viv)
		cout << "\t\tres = " << v << endl;
	return v;
}

void get(int v, ll w) {
	int l = -1;
	int r = d[v] + 1;
	while (l + 1 < r) {
		int m = l + r >> 1;
		int pr = LA(v, d[v] - m);
		if (vec[pr].F == 0)
			l = m;
		else
			r = m;
	}
	if (viv)
		cout << "lr = " << l << ' ' << r << endl;
	ll cnt = 0, pay = 0;
	while (r <= d[v] && w) {
		if (viv)
			cout << "!!! " << v << ' ' << d[v] << ' ' << r << endl;
		int pr = LA(v, d[v] - r);
		if (viv)
			cout << "see " << pr << endl;
		int here = min(vec[pr].F, w);
		if (viv)
			cout << "GET " << here << " from " << pr << endl;
		w -= here;
		vec[pr].F -= here;
		if (viv)
			cout << "\tLEFT " << vec[pr].F << endl;
		cnt += here;
		pay += here * vec[pr].S;
		r++;
	}
	cout << cnt << ' ' << pay << endl;
}

int nxt;
void work() {
	int tp;
	cin >> tp;
	if (tp == 1) {
		int p, a, c;
		cin >> p >> a >> c;
		add(p, a, c, nxt);
	}
	if (tp == 2) {
		add(0, 0, 0, nxt);
		int v, w;
		cin >> v >> w;
		get(v, w);
	}
	nxt++;
}

void solve() {
	int a0, c0;
	cin >> q >> a0 >> c0;
	pp.resize(K, {0});
	p.push_back(0);
	d.push_back(0);
	add(0, a0, c0, 0);

	nxt = 1;
	while (q--) {
		work();
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