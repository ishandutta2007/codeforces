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
vector<vector<int>> e;
vector<int> d, p, q;
vector<bool> dead, leaf;
vector<vector<int>> cool, left_l;
vector<pii> ans;
set<pii> er, ex;
bool viv = false;

void to_er(int u, int v) {
	if (viv)
		cout << "\t\t\tto_er(" << u << ", " << v << ")" << endl;
	er.insert({u, v});
	er.insert({v, u});
}

void DFS(int v, int c = 0) {
	if (viv)
		cout << "\t\tDFS(" << v << ", " << c << ")" << endl;
	d[v] = c;
	for (auto u : e[v]) {
		if (d[u] == -1) {
			p[u] = v;
			DFS(u, c + 1);
		} else {
			if (d[u] + 1 < d[v]) {
				to_er(u, v);
				int now = v;
				while (now != u) {
					to_er(now, p[now]);
					now = p[now];
				}
				if (viv)
					cout << "ERASED!" << endl;
			}
		}
	}
	q.push_back(v);
}

void DFS2(int v, int c = 0) {
	if (viv)
		cout << "\t\tDFS2(" << v << ", " << c << ")" << endl;
	d[v] = c;
	for (auto u : e[v]) {
		if (d[u] == -1) {
			p[u] = v;
			DFS2(u, c + 1);
		}
	}
	q.push_back(v);
}

void rebuild() {
	if (viv)
		cout << "\trebuild()" << endl;
	ex.clear();
	for (int i = 0; i < n; i++) {
		vector<int> st;
		for (auto u : e[i]) {
			if (!er.count({i, u})) {
				ex.insert({u, i});
				ex.insert({i, u});
				st.push_back(u);
			}
			else 
				if (viv)
					cout << "\t\tforget: " << i << ' ' << u << endl;
		}
		e[i] = st;		
	}
}

void read() {
	if (viv)
		cout << "read()" << endl;
	cin >> n >> m;
	if (n == 0 && m == 0) {
		exit(0);
	}
	e.assign(n, {});
	for (int i = 0; i < m; i++) {
		vector<int> p;
		int k;
		cin >> k;
		p.resize(k);
		for (auto &i : p)
			cin >> i, i--;
		for (int i = 1; i < k; i++) {
			e[p[i - 1]].push_back(p[i]);
			e[p[i]].push_back(p[i - 1]);
		}
	}	
	d.assign(n, -1);
	p.assign(n, -1);
	er.clear();
	for (int i = 0; i < n; i++)
		if (d[i] == -1)
			DFS(i);
	rebuild();
}

bool add(int u, int v) {
	if (ex.find({u, v}) != ex.end()) {
		return false;
		cout << u << " and " << v << endl;
	}
	assert(ex.find({u, v}) == ex.end());
	ans.push_back({u, v});
	return true;
}

void check(int v) {
	if (viv)
		cout << "\t\tcheck(" << v << ")" << endl;

	vector<int> c;
	vector<int> l;
	for (auto u : e[v]) {
		if (d[u] > d[v] && !dead[v]) {
			for (auto s : cool[u])
				c.push_back(s);
			if (leaf[u])
				l.push_back(u);
		}
	}

	if (viv) {
		cout << "\t\t\tl:";
		for (auto i : l)
			cout << i << ' ';
		cout << endl;
		cout << "\t\t\tc:";
		for (auto i : c)
			cout << i << ' ';
		cout << endl;
	}

	while (c.size() >= 2) {
		int v1 = c.back();
		c.pop_back();
		int v2 = c.back();
		c.pop_back();
		add(v1, v2);
	}
	while (l.size() >= 3) {
		int v1 = l.back();
		l.pop_back();
		int v2 = l.back();
		l.pop_back();
		dead[v1] = true;
		dead[v2] = true;
		add(v1, v2);		
	}
	if (c.size() && l.size() == 2) {
		int v1 = c.back();
		c.pop_back();
		int v2 = l.back();
		l.pop_back();
		add(v1, v2);		
	}
	if (c.size()) {
		cool[v].push_back(c[0]);
		if (l.size())
			l.pop_back();
	}
	if (l.size()) {
		if (l.size() == 1) {
			cool[v].push_back(v);
		}
		if (l.size() == 2) {
			cool[v].push_back(l[0]);
		}
	}
	if (c.empty() && l.empty()) {
		leaf[v] = true;
	}
	left_l[v] = l;

	if (d[v] == 0 && c.size()) {
		int u = c[0];
		if (left_l[u].size()) {
			int t = left_l[u][0];
			assert(add(t, v));
		} else {
			assert(add(u, v));
		}
	}
}

void check_old(int v) {
	if (viv)
		cout << "\t\tcheck_old(" << v << ")" << endl;
	leaf[v] = true;
	vector<int> l;
	for (auto u : e[v])
		if (d[u] > d[v] && !dead[u]) {
			if (leaf[u])
				l.push_back(u);
		}
	while (l.size() >= 3) {
		int v1 = l.back();
		l.pop_back();
		int v2 = l.back();
		l.pop_back();
		dead[v1] = true;
		dead[v2] = true;
		add(v1, v2);
	}
	if (l.size() == 2) {
		cool[v].push_back(l[0]);
	}
	if (l.size() == 1) {
		cool[v].push_back(v);
	}
	for (auto u : e[v])
		if (d[u] > d[v] && !dead[u]) {
			leaf[v] = false;
			for (auto s : cool[u]) 
				cool[v].push_back(s);
		}
	if (viv) {
		cout << "\t\t\tsee: leaf. " << leaf[v] << "; " << "cool. ";
		for (auto i : cool[v])
			cout << i << ", ";
		cout << endl;
	}
	if (cool[v].size() >= 2) {
		for (int i = 0; i < cool[v].size(); i++)
			if (cool[v][i] == v)
				swap(cool[v][i], cool[v][0]);
	}
	while (cool[v].size() >= 2) {
		int v1 = cool[v].back();
		cool[v].pop_back();
		int v2 = cool[v].back();
		cool[v].pop_back();
		// if (v1 == v || v2 == v)
		// 	dead[v] = true;
		add(v1, v2);
	}

	if (d[v] == 0 && cool[v].size() && cool[v][0] != v) {
		int u = cool[v][0];
		bool bad = true;
		for (auto s : e[u]) 
			if (bad) {
				if (d[s] > d[u] && !dead[s]) {
					if (add(v, s))	
						bad = false;
				}
		}
		for (auto s : e[v]) 
			if (bad) {
				if (s != u && !dead[s]) {
					if (add(u, s))
						bad = false;
				}
		}
		if (bad) {
			if (add(u, v))
				bad = false;
		}
		assert(!bad);
	}
}

void work(int v) {
	if (viv)
		cout << "\twork(" << v << ")" << endl;
	q.clear();
	DFS2(v);
	for (auto u : q)
		check(u);
}

void work() {
	if (viv)
		cout << "work()" << endl;
	d.assign(n, -1);
	p.assign(n, -1);
	dead.assign(n, false);
	leaf.assign(n, false);
	cool.assign(n, {});
	left_l.assign(n, {});
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (d[i] == -1 && e[i].size() == 1) {
			work(i);
		}
	}
}

void write() {
	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
	}
	cout << '\n';
}

void solve() {
	if (viv)
		cout << "solve()" << endl;
	read();
	work();
	write();
}


int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (true)
		solve();

	return 0;
}


/*
1
1 4

0

1
4 5

2
1 3
6 7

0

1
1 3

1
1 4

1
1 5

1
1 6

1
1 7

1
3 1

2
6 5
3 2

1
7 2

1
4 2

3
7 6
5 4
2 3





*/