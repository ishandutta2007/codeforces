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

ll n, q;
vector<int> v;
vector<vector<int>> pl;
bool viv = false;

int cnt(int val, int r) {
	return pl[val].size() - (lower_bound(pl[val].begin(), pl[val].end(), r) - pl[val].begin());
}

int cnt(int val, int l, int r) {
	r++;	
	return cnt(val, l) - cnt(val, r);
}

struct Tree {
	int n, s;
	vector<int> t;

	Tree() {}

	Tree(vector<int> v) {
		build(v);
	}

	int upd(int v, int l, int r) {
		if (t[v] != -1)
			return t[v];
		int m = l + r >> 1;
		int va = upd(2 * v, l, m);
		int vb = upd(2 * v + 1, m, r);
		return t[v] = (cnt(va, l, r - 1) >= cnt(vb, l, r - 1)) ? va : vb;
	}

	void build(vector<int> v) {
		n = v.size();
		s = 1;
		while (s < n)
			s <<= 1;
		t.resize(2 * s);
		for (int i = 0; i < n; i++)
			t[s + i] = v[i];
		for (int i = n; i < s; i++)
			t[s + i] = n;
		for (int i = 1; i < s; i++)
			t[i] = -1;
		upd(1, 0, s);
	}

	vector<int> work(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return {};
		if (l <= tl && tr <= r) {
			return {t[v]};
		}
		int tm = tl + tr >> 1;
		auto va = work(l, r, 2 * v + 0, tl, tm);
		auto vb = work(l, r, 2 * v + 1, tm, tr);
		for (auto i : vb)
			va.push_back(i);
		return va;
	}
} t;

void prepare() {
	pl.resize(n + 1);
	for (int i = 0; i < n; i++) {
		pl[v[i]].push_back(i);
	}
	t.build(v);
}


void solver() {
	int l, r;
	cin >> l >> r;
	l--, r--;
	auto vals = t.work(l, r + 1, 1, 0, t.s);
	int mx = 0;
	for (auto i : vals)
		mx = max(mx, cnt(i, l, r));
	int lft = (r + 1 - l) - mx;
	int need = max(0, mx - lft - 1);
	need++;
	cout << need << '\n';
}

void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	prepare();
	while (q--)
		solver();

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