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

ll n, m;
vector<vector<int>> v, used_by;
vector<set<int>> ones;
set<int> ans;
bool viv = false;

void prepare() {
	cin >> n >> m;
	v.assign(n, {});
	for (auto &l : v) {
		int k;
		cin >> k;
		l.resize(k);
		for (auto &i : l)
			cin >> i, i--;
	}

	used_by.assign(m, {});
	ones.assign(3, {});
	ans.clear();
	for (int i = 0; i < n; i++) {
		for (auto b : v[i]) {
			used_by[b].push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
		ones[v[i].size()].insert(i);
}

void get_it() {
	int num = *ones[1].begin();
	ones[1].erase(num);
	ans.insert(num);
	assert(v[num].size() == 1);
	int b = v[num].back();	
	for (auto i : used_by[b]) {
		assert(v[i].size());
		if (v[i].back() != b)
			swap(v[i][0], v[i].back());
		assert(v[i].back() == b);

		ones[v[i].size()].erase(i);
		v[i].pop_back();
		ones[v[i].size()].insert(i);
	}
}

vector<int> p, sz;

int pp(int v) {
	if (p[v] == v)
		return v;
	return p[v] = pp(p[v]);
}

bool join(int v, int u) {
	int gv = pp(v);
	int gu = pp(u);
	if (gv == gu)
		return false;

	if (sz[gv] < sz[gu])
		swap(gu, gv);

	sz[gv] += sz[gu];
	p[gu] = gv;
	return true;
}

void make_DSU() {
	p.assign(m, 0);
	sz.assign(m, 1);
	for (int i = 0; i < m; i++)
		p[i] = i;
	for (int i = 0; i < n; i++) {
		assert(v[i].size() != 1);
		if (v[i].size() == 2) {
			int v1 = v[i][0];
			int v2 = v[i][1];
			if (join(v1, v2))
				ans.insert(i);
		}
	}
}

void solve() {
	prepare();
	if (viv) {
		for (auto i : ones)
			cout << i.size() << ' ';
		cout << endl;
	}
	while (ones[1].size())
		get_it();
	if (viv) {
		cout << "num used like ones: ";
		for (auto i : ans)
			cout << i << ' ';
		cout << endl;
	}
	make_DSU();
	ll cnt = 1;
	for (auto i : ans) {
		cnt <<= 1;
		cnt %= mod;
	}
	cout << cnt << ' ' << ans.size() << '\n';
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
	// cin >> t;
	while (t--)
		solve();

	return 0;
}