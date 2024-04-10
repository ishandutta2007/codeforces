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

int n, m;
vector<set<int>> e;
vector<vector<int>> kids;
vector<int> d;

vector<vector<int>> c;
set<pii> bad;
set<int> unused;
vector<bool> used;
bool viv = false;

struct cmp {
	bool operator()(const pii &a, const pii &b) {
		if (a.S == b.S)
			return a.F < b.F;
		return a.S > b.S;
	}
};

void DFS(int v, int D) {
	d[v] = D;
	set<int> left;
	unused.erase(v);	
	for (auto u : unused) {
		if (e[v].find(u) == e[v].end()) {
			kids[v].push_back(u);
		} else
			left.insert(u);
	}
	if (viv) {
		cout << v << ": ";
		for (auto i : kids[v])
			cout << i << ' ';
		cout << endl;
	}
	unused = left;
	for (auto u : kids[v])
		DFS(u, D + 1);

	bool work = false;
	for (auto u : kids[v])
		if (!used[u])
			work = true;

	if (work) {
		c.push_back({});
		c.back().push_back(v);
		used[v] = true;
		for (auto u : kids[v])
			if (!used[u]) {
				c.back().push_back(u);
				used[u] = true;
			}
	}

	if (!work && d[v] == 0) {
		if (e[v].size() != n - 1) {
			assert(c.size());
			c.back().push_back(v);
		} else {
			c.push_back({});
			c.back().push_back(v);
		}
		used[v] = true;
	}
}

void solve() {
	cin >> n >> m;
	e.assign(n, {});
	kids.assign(n, {});
	c.clear();
	bad.clear();

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].insert(b);
		e[b].insert(a);
		bad.insert({a, b});
		bad.insert({b, a});
	}
	d.assign(n, -1);
	used.assign(n, false);
	unused.clear();
	for (int i = 0; i < n; i++) 
		unused.insert(i);
	for (int i = 0; i < n; i++) {
		if (d[i] == -1)
			DFS(i, 0);
	}


	vector<int> p1(n, -1), p2(n, -1);
	int nxt = 0;
	for (auto cc : c) {
		if (viv) {
			cout << "work: ";
			for (auto i : cc)
				cout << i << ' ';
			cout << endl;
		}
		vector<int> num;
		for (int i = nxt; i < nxt + cc.size(); i++)
			num.push_back(i);
		num.push_back(nxt);
		reverse(num.begin(), num.end());
		for (int i = 0; i < cc.size(); i++) {
			p1[cc[i]] = num[i];
			p2[cc[i]] = num[i + 1];
		}
		nxt += cc.size();
	}

	if (viv)
		cout << "ANS1: ";
	for (auto &i : p1)
		cout << i + 1 << ' ';
	cout << '\n';
	if (viv)
		cout << "ANS2: ";
	for (auto &i : p2)
		cout << i + 1 << ' ';
	cout << '\n';

	if (viv) {
		cout << endl;
		for (auto p : bad) {
			if ((p1[p.F] > p1[p.S]) ^ (p2[p.F] > p2[p.S])) {
				cout << "____LOOK____: " << p.F << ' ' << p.S << '\n';
				assert(false);
			}
		}
	}
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