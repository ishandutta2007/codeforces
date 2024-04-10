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
int r1, r2;
vector<vector<int>> e;
vector<pii> all_e;
vector<pii> act;
bool viv = false;


struct Tree {
	int s = 1;
	int n = 0;
	vector<pii> t;
	vector<bool> swp;

	void build(vector<int> dist, vector<pii> seg) {
		if (viv) {
			for (auto i : dist)
				cout << i << ' ';
			cout << endl;
			for (auto p : seg)
				cout << p.F << ' ' << p.S << "; ";
			cout << endl;
		}
		n = dist.size();
		s = 1;
		while (s < n)
			s <<= 1;		
		t.resize(2 * s);
		swp.resize(2 * s, false);
		for (int i = 0; i < n; i++)
			t[s + i] = {dist[i], 0};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		if (viv)
			show();
	}


	void upd(int v) {
		if (v >= s)
			return;
		t[v].F = max(t[2 * v + 0].F, t[2 * v + 1].F);
		t[v].S = max(t[2 * v + 0].S, t[2 * v + 1].S);
	}

	void push(int v) {
		if (v >= s)
			return;
		if (!swp[v])
			return;
		swp[2 * v + 0] = swp[2 * v + 0] ^ true;
		swp[2 * v + 1] = swp[2 * v + 1] ^ true;
		swap(t[2 * v + 0].F, t[2 * v + 0].S);
		swap(t[2 * v + 1].F, t[2 * v + 1].S);
		swp[v] = false;
	}

	void _xor(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return;
		push(v);
		if (l <= tl && tr <= r) {
			swap(t[v].F, t[v].S);
			swp[v] = swp[v] ^ true;
			return;
		}

		int _time = tl + tr >> 1;
		_xor(l, r, 2 * v + 0, tl, _time);
		_xor(l, r, 2 * v + 1, _time, tr);
		upd(v);
	}

	void _xor(pii p) {
		int l = p.F, r = p.S;
		r++;
		_xor(l, r, 1, 0, s);
	}

	int get_ans() {
		if (viv)
			show();
		return t[1].F;
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
} t[2];



vector<int> d;

void DFS1(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1)
			DFS1(u, c + 1);
}

int far(int v) {
	d.clear();
	d.resize(n, -1);
	DFS1(v);
	int u = 0;
	for (int i = 0; i < n; i++)
		if (d[i] > d[u])
			u = i;
	return u;
}

vector<int> dist[2];
vector<pii> seg[2];
int _time;

void DFS2(int v, int root, int c = 0) {
	dist[root == r2][_time] = c;
	seg[root == r2][v].F = _time++;
	for (auto u : e[v])
		if (seg[root == r2][u].F == -1)
			DFS2(u, root, c + 1);
	dist[root == r2][_time] = c;
	seg[root == r2][v].S = _time++;
}

void work(int root) {
	dist[root == r2].resize(2 * n, -1);
	seg[root == r2].resize(n, (pii){-1, -1});
	_time = 0;
	DFS2(root, root);
	t[root == r2].build(dist[root == r2], seg[root == r2]);
}

void prepare() {
	r1 = far(0);
	r2 = far(r1);
	work(r1);
	work(r2);
}

int dis(int root, int v) {
	int tp = (root == r2);
	int pl = seg[tp][v].F;
	return dist[tp][pl];
}

void change(pii p, int root) {
	int down = p.F;
	int up = p.S;
	if (dis(root, up) > dis(root, down))
		swap(down, up);
	auto sg = seg[root == r2][down];
	t[root == r2]._xor(sg);
}

void change(pii p) {
	change(p, r1);
	change(p, r2);
}

void get_ans() {
	int ans = 0;
	ans = max(ans, t[0].get_ans());
	ans = max(ans, t[1].get_ans());
	cout << ans << '\n';
}

void solve() {
	cin >> n;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
		if (c)
			act.push_back({a, b});
		all_e.push_back((pii){a, b});
	}
	prepare();
	for (auto p : act)
		change(p);

	int q;
	cin >> q;
	while (q--) {
		int num;
		cin >> num;
		num--;
		change(all_e[num]);
		get_ans();
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