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

int n, m, w;
vector<vector<int>> v;
bool viv = false;

bool f(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return false;
	if (v[i][j] == -1)
		return false;
	return true;
}

vector<pii> get_fr(pii a) {
	vector<pii> res;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if ((i == 0) ^ (j == 0))
				if (f(a.F + i, a.S + j))
					res.push_back({a.F + i, a.S + j});
	return res;
}

int num(pii pr) {
	return pr.F * m + pr.S;
}

int num(ll a, ll b) {
	return num({a, b});
}

vector<ll> s, t;

void BFS_s() {
	if (viv)
		cout << "BFS_s()" << endl;
	s.resize(n * m, inf);
	s[0] = 0;
	deque<pii> q = {{0, 0}};
	while (q.size()) {		
		int v = num(q.front());
		if (viv)
			cout << "\ts " << v << endl;
		vector<pii> fr = get_fr(q.front());
		q.pop_front();
		for (auto pr : fr) {
			int u = num(pr);
			if (s[u] > s[v] + w) {
				s[u] = s[v] + w;
				q.push_back(pr);
			}
		}
	}
}

void BFS_t() {
	if (viv)
		cout << "BFS_s()" << endl;
	t.resize(n * m, inf);
	t[n * m - 1] = 0;
	deque<pii> q = {{n - 1, m - 1}};
	while (q.size()) {		
		int v = num(q.front());
		if (viv)
			cout << "\tt " << v << endl;
		vector<pii> fr = get_fr(q.front());
		q.pop_front();
		for (auto pr : fr) {
			int u = num(pr);
			if (t[u] > t[v] + w) {
				t[u] = t[v] + w;
				q.push_back(pr);
			}
		}
	}
}

void solve() {
	cin >> n >> m >> w;
	v.resize(n, vector<int>(m));
	for (auto &l : v)
		for (auto &i : l)
			cin >> i;
	BFS_s();
	BFS_t();

	ll ans = inf;
	ll ps = inf;
	ll pt = inf;
	ans = t[0];
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			if (v[i][j] > 0) {
				int ver = num(i, j);
				ps = min(ps, s[ver] + v[i][j]);
				pt = min(pt, t[ver] + v[i][j]);
			}
		}
	}
	ans = min(ans, ps + pt);
	if (ans == inf)
		ans = -1;
	cout << ans << '\n';
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