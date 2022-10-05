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
// const long long mod = 9;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, N;
vector<pii> v;
vector<vector<pii>> old;
vector<pii> old_vec;
vector<vector<int>> d, u, l, r;
vector<vector<int>> num;
bool viv = false;

int V = 0;
vector<vector<int>> e;
vector<ll> vx;
vector<ll> vy;

void read() {
	cin >> N;
	v.resize(N);
	for (auto &p : v)
		cin >> p.F >> p.S;
	set<int> x, y;
	map<int, int> mpx, mpy;
	map<int, set<int>> rows, columns;
	for (auto p : v) {
		x.insert(p.F);
		y.insert(p.S);
		rows[p.F].insert(p.S);
		columns[p.S].insert(p.F);
	}	

	for (auto row: rows) {
		vector<int> rr;
		for (auto val : row.S)
			rr.push_back(val);
		for (int i = 1; i < rr.size(); i++)
			y.insert((rr[i - 1] + rr[i]) / 2);
	}
	for (auto column: columns) {
		vector<int> cc;
		for (auto val : column.S)
			cc.push_back(val);
		for (int i = 1; i < cc.size(); i++)
			x.insert((cc[i - 1] + cc[i]) / 2);
	}

	int nx = 0;
	for (auto val : x) 
		mpx[val] = nx++, vx.push_back(val);
	int ny = 0;
	for (auto val : y) 
		mpy[val] = ny++, vy.push_back(val);

	if (viv) {
		cout << "vx = ";
		for (auto val : vx)
			cout << val << ' ';
		cout << endl;
		cout << "vy = ";
		for (auto val : vy)
			cout << val << ' ';
		cout << endl;
	}

	n = x.size();
	m = y.size();
	if (viv)
		cout << "n, m = " << n << ' ' << m << endl;
	old.resize(n, vector<pii>(m, {mod, mod}));
	for (auto &p : v) {
		auto oldp = p;
		p.F = mpx[p.F];
		p.S = mpy[p.S];
		old[p.F][p.S] = oldp;
	}

	if (viv) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				auto p = old[i][j];
				cout << p.F << ' ' << p.S << "; ";
			}
			cout << endl;
		}
	}
}

bool ex(int i, int j) {
	return old[i][j] != (pii){mod, mod};
}

void prepare() {
	d.resize(n, vector<int>(m, n));
	u.resize(n, vector<int>(m, -1));
	r.resize(n, vector<int>(m, m));
	l.resize(n, vector<int>(m, -1));

	num.resize(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0) 
				u[i][j] = u[i - 1][j];
			if (j > 0) 
				l[i][j] = l[i][j - 1];
			if (ex(i, j)) {
				u[i][j] = i, l[i][j] = j;
				num[i][j] = V++;
				old_vec.push_back(old[i][j]);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (i < n - 1) 
				d[i][j] = d[i + 1][j];
			if (j < m - 1) 
				r[i][j] = r[i][j + 1];
			if (ex(i, j))
				d[i][j] = i, r[i][j] = j;
		}
	}
	if (viv) {
		cout << "V = " << V << endl;
		cout << "old_vec: ";
		for (auto p : old_vec)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
	}
}

vector<int> col;
int c;
void DFS(int v, int c) {
	col[v] = c;
	for (auto u : e[v])
		if (col[u] == -1)
			DFS(u, c);
}
void do_DFS() {
	col.assign(V, -1);
	c = 0;
	for (int v = 0; v < V; v++)
		if (col[v] == -1)
			DFS(v, c++);
}

bool nice(int u, int v, int t) {
	pii p1 = old_vec[u];
	pii p2 = old_vec[v];
	if (!(p1.F == p2.F || p1.S == p2.S)) {
		cout << p1.F << ' ' << p1.S << "; ";
		cout << p2.F << ' ' << p2.S << "; ";
		cout << endl;
		assert(p1.F == p2.F || p1.S == p2.S);
	}
	if (viv)
		cout << "\t\t\t\tnice(" << p1.F << ' ' << p1.S << "; " << p2.F << ' ' << p2.S << ")" << endl;
	ll diff = 0;
	diff += abs(p1.F - p2.F);
	diff += abs(p1.S - p2.S);
	return diff <= t;
}

void build(int t) {
	e.assign(V, {});
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (l[i][j] == j) {
				int j2 = l[i][j - 1];
				if (j2 != -1) {
					int u = num[i][j];
					int v = num[i][j2];
					if (viv)
						cout << "pot edge " << u << ' ' << v << endl;
					if (nice(u, v, t)) {
						if (viv)
							cout << "Add " << u << ' ' << v << endl;
						e[u].push_back(v);
						e[v].push_back(u);
					}
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (u[i][j] == i) {
				int i2 = u[i - 1][j];
				if (i2 != -1) {
					int u = num[i][j];
					int v = num[i2][j];
					if (viv)
						cout << "pot edge " << u << ' ' << v << endl;
					if (nice(u, v, t)) {
						if (viv)
							cout << "Add " << u << ' ' << v << endl;
						e[u].push_back(v);
						e[v].push_back(u);
					}
				}
			}
		}
	}
	if (viv)
		cout << "Graph built" << endl;

	do_DFS();	
}

bool can(int t) {
	if (viv) {
		cout << "\n\n\n\n\n\n";
		cout << "can(" << t << ")" << endl;
	}
	build(t);
	if (c > 4) 
		return false;
	if (viv) {
		cout << "col.size() = " << col.size() << endl;
		cout << "col = ";
		for (auto i : col)
			cout << i << ' ';
		cout << endl;
	}
	if (viv)
		cout << "c = " << c << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (l[i][j] != j && u[i][j] != i) {
				int x = vx[i];
				int y = vy[j];
				if (x != mod && y != mod) {
					old_vec.push_back({x, y});
					if (viv)
						cout << "Try " << i << ' ' << j << " with " << x << ' ' << y << endl;
					set<int> cols;
					if (l[i][j] != -1) {
						int j2 = l[i][j];
						int v = num[i][j2];
						if (viv)
							cout << "\ttouch " << v << endl;
						if (nice(v, V, t)) {
							if (viv)
								cout << "\t\tADD " << v << endl;
							cols.insert(col[v]);
						}
					}
					if (u[i][j] != -1) {
						int i2 = u[i][j];
						int v = num[i2][j];
						if (viv)
							cout << "\ttouch " << v << endl;
						if (nice(v, V, t)) {
							if (viv)
								cout << "\t\tADD " << v << endl;
							cols.insert(col[v]);
						}
					}
					if (r[i][j] != m) {
						int j2 = r[i][j];
						int v = num[i][j2];
						if (viv)
							cout << "\ttouch " << v << endl;
						if (nice(v, V, t)) {
							if (viv)
								cout << "\t\tADD " << v << endl;
							cols.insert(col[v]);
						}
					}
					if (d[i][j] != n) {
						int i2 = d[i][j];
						int v = num[i2][j];
						if (viv)
							cout << "\ttouch " << v << endl;
						if (nice(v, V, t)) {
							if (viv)
								cout << "\t\tADD " << v << endl;
							cols.insert(col[v]);
						}
					}
					if (viv)
						cout << "see: " << cols.size() << " out of " << c << endl;
					old_vec.pop_back();
					if (cols.size() == c) {
						if (viv)
							cout << "NICE\tNICE\tNICE\t\n";
						return true;
					}
				}
			}
		}
	}
	return false;
}

void solver() {
	ll l = 0;
	ll r = 2 * mod;
	// r = 239;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (can(m))
			r = m;
		else
			l = m;
	}
	if (r == 2 * mod)
		r = -1;
	cout << r << '\n';
}

void solve() {
	if (viv) 
		cout << "read()" << endl;
	read();	
	if (viv) 
		cout << "prepare()" << endl;
	prepare();
	if (viv) 
		cout << "solver()" << endl;
	solver();
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}