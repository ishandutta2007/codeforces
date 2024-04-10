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
vector<string> v;
vector<vector<pll>> ans;
bool viv = false;

void make_1(int x, int y) {
	if (viv)
		cout << "\tmake_1(" << x << ' ' << y << ")" << endl;
	ans.back().push_back({x, y});
	if (v[x][y] == '1')
		v[x][y] = '0';
	else
		v[x][y] = '1';
}

void make(int x1, int y1, int x2, int y2) {
	ans.push_back({});
	make_1(x1, y1);
	make_1(x1, y2);
	make_1(x2, y1);
}

void make_f_wo(int x1, int y1, int x2, int y2, int xb, int yb) {
	ans.push_back({});
	ll cnt = 0;
	if (x1 != xb || y1 != yb)
		make_1(x1, y1), cnt++;
	if (x1 != xb || y2 != yb)
		make_1(x1, y2), cnt++;
	if (x2 != xb || y1 != yb)
		make_1(x2, y1), cnt++;
	if (x2 != xb || y2 != yb)
		make_1(x2, y2), cnt++;
	assert(cnt == 3);
}

void make_wo(int xb, int yb) {
	ans.push_back({});
	ll cnt = 0;
	if (n - 1 != xb || m - 1 != yb)
		make_1(n - 1, m - 1), cnt++;
	if (n - 1 != xb || m - 2 != yb)
		make_1(n - 1, m - 2), cnt++;
	if (n - 2 != xb || m - 1 != yb)
		make_1(n - 2, m - 1), cnt++;
	if (n - 2 != xb || m - 2 != yb)
		make_1(n - 2, m - 2), cnt++;
	assert(cnt == 3);
}

bool g(int i, int j) {
	return (v[i][j] == '1');
}

void check() {
	if (viv) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << v[i][j];		
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			assert(v[i][j] == '0');
}

void write() {
	cout << ans.size() << '\n';
	for (auto &vec : ans) {
		for (auto &p : vec) {
			cout << p.F + 1 << ' ' << p.S + 1 << ' ';
		}
		cout << '\n';
	}
	if (viv)
		cout << endl;
}

void solve() {
	cin >> n >> m;
	v.clear();
	ans.clear();
	v.resize(n);
	for (auto &s : v) {
		cin >> s;		
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (g(i, j))
				if (i == n - 2 && (j == m - 1 || j == m - 2)) {

				} else {
					if (j == 0) {
						make_f_wo(i, j, i + 1, j + 1, i + 1, j + 1);
					} else {
						make_f_wo(i, j - 1, i + 1, j, i, j - 1);
					}
				}
		}
	}
	for (int j = 0; j < m - 2; j++) {
		int i = n - 1;
		if (g(i, j) || g(i - 1, j)) {
			pll p = {i, j + 1};
			if (!g(i, j))
				p = {i, j};
			if (!g(i - 1, j))
				p = {i - 1, j};
			make_f_wo(i - 1, j, i, j + 1, p.F, p.S);
		}
	}
	if (g(n - 2, m - 2))
		make(n - 2, m - 2, n - 1, m - 1);

	int cnt = 0;
	cnt += (v[n - 1][m - 1] == '1');
	cnt += (v[n - 1][m - 2] == '1');
	cnt += (v[n - 2][m - 1] == '1');
	if (cnt == 3) 
		make_wo(n - 2, m - 2);
	else {
		if (cnt == 0) {

		} else {
			if (cnt == 1) {
				make_wo(n - 2, m - 2);
				vector<pll> bad;
				for (int i = n - 2; i < n; i++)
					for (int j = m - 2; j < m; j++)
						if (v[i][j] == '1')
							bad.push_back({i, j});
				// for (auto p : bad)
				// 	cout << p.F << ' ' << p.S << endl;
				for (auto p : bad)
					make_wo(p.F, p.S);
			} else {
				if (cnt == 2) {
					vector<pll> bad;
					for (int i = n - 2; i < n; i++)
						for (int j = m - 2; j < m; j++)
							if (v[i][j] == '1')
								bad.push_back({i, j});
					for (auto p : bad)
						make_wo(p.F, p.S);
				} else {
					assert(false);
				}
			}
		}
	}	
	check();
	write();
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