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
vector<ll> v, look, ans;
bool viv = false;
deque<pii> ch;

struct dsu {
	vector<int> p;

	dsu() {}

	// dsu(dsu &an) {
	// 	p = an.p;
	// }

	dsu(int n) {
		build(n);
	}

	void build(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	void clear() {
		p.clear();
	}

	int pp(int v) {
		if (viv)
			cout << "\tpp " << v << endl;
		if (p[v] == v) {
			if (viv)
				cout << "\tis " << v << endl;
			return v;
		}
		return p[v] = pp(p[v]);
	}	

	void un(int u, int v) {
		u = pp(u);
		v = pp(v);
		if (u == v)
			return;
		p[v] = u;
		if (viv) {
			cout << v << " to " << u << endl;
			cout << "p = ";
			for (auto i : p)
				cout << i << ' ';
			cout << endl;
		}
	}
};
dsu d;

int get_look(int p) {
	look[p] = look[(p + 1) % n];
	return look[p];
}

void work() {
	auto p = ch.front();
	ch.pop_front();

	int p1 = p.F;
	int p2 = p.S;
	// if (look[p1] != p1 || look[p2] != p2)
	// 	return;
	if (d.pp(p1) != p1)
		return;
	if (d.pp(p2) != p2)
		return;
	if (__gcd(v[p1], v[p2]) > 1)
		return;

	if (viv)
		cout << "work " << p1 << ' ' << p2 << endl;
	ans.push_back(p2);
	if (p1 == p2)
		return;
	d.un(d.pp((p2 + 1) % n), p2);
	if (viv)
		cout << "add " << p1 << ' ' << d.pp(p2) << endl;
	ch.push_back((pii){p1, d.pp(p2)});
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	look.resize(n);
	for (int i = 0; i < n; i++)
		look[i] = i;

	d.clear();
	d.build(n);

	ch.clear();
	ans.clear();
	for (int i = 0; i < n; i++)
		ch.push_back({i, (i + 1) % n});
	while (ch.size())
		work();

	cout << ans.size() << "  ";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
	if (viv)
		cout << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}