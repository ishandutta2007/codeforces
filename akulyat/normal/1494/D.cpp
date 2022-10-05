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
vector<int> c;
bool viv = false;

set<int> s;
unordered_map<int, vector<pii>> mp;

vector<int> d, who, p;
vector<vector<int>> e;
int nxt;

void DFS(vector<vector<int>> &gr, int v) {
	d[v] = gr.size() - 1;
	gr.back().push_back(v);
	for (auto u : e[v])
		if (d[u] == -1)
			DFS(gr, u);
}

void work(int val) {
	vector<vector<int>> gr;
	for (auto p : mp[val]) {
		int u = p.F;
		int v = p.S;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (auto p : mp[val]) {
		int u = p.F;
		int v = p.S;
		if (d[u] == -1) {
			gr.push_back({});
			DFS(gr, u);
		}
	}

	if (viv) {
		cout << "val: " << val << endl;
		cout << "gr:\n";
		for (auto l : gr) {
			for (auto v : l)
				cout << v << ' ';
			cout << '\n';
		}
		cout << endl;
	}

	for (auto &l : gr) {
		c.push_back(val);
		for (auto v : l) {
			v = who[v];
			while (v >= p.size())
				p.push_back(-1);
			p[v] = nxt;
			if (viv)
				cout << "see " << v << ' ' << nxt << '\n';
		}
		for (auto v : l) {
			who[v] = nxt;
		}
		nxt++;
	}

	for (auto &l : gr)
		for (auto v : l) {
			e[v].clear();
			d[v] = -1;
		}
}

void solve() {
	cin >> n;
	v.resize(n, vector<int>(n));
	for (auto &l : v)
		for (auto &i : l)
			cin >> i;
	for (int i = 0; i < n; i++)
		c.push_back(v[i][i]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
 			s.insert(v[i][j]);
 			mp[v[i][j]].push_back({i, j});
		}
	d.resize(n, -1);
	who.resize(n);
	for (int i = 0; i < n; i++)
		who[i] = i;
	e.resize(n);
	p.resize(n, -1);
	nxt = n;
	for (auto val : s)
		work(val);

	cout << nxt << '\n';
	for (auto i : c)
		cout << i << ' ';
	cout << '\n';
	cout << nxt << '\n';;
	for (int i = 0; i < nxt; i++) {
		if (i < p.size() && p[i] != -1)
			cout << i + 1 << ' ' << p[i] + 1 << '\n';
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