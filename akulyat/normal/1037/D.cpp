#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, m;
vector<vector<int>> e;
vector<ll> col;
vector<ll> vec;
bool viv = false;

void DFS(int v, ll c) {
	col[v] = c;
	for (auto s : e[v])
		if (col[s] == -1)
			DFS(s, c + 1);
}

void bad() {
	cout << "No";
	exit(0);
}

vector<int> BFS(int root) {
	vector<int> d(n, mod); d[root] = 0;
	vector<int> p(n, -1);
	vector<int> q(1, root); int st = 0;
	while (st < q.size()) {
		int v = q[st++];
		for (auto s : e[v])
			if (d[s] > d[v] + 1) {
				d[s] = d[v] + 1;
				p[s] = v;
				q.push_back(s);
			}
	}
	if (vec[0] != 0)
		bad();
	vector<ll> par;
	if (n > 1)
		par.push_back(0);
	for (int i = 1; i < n; i++)
		if (p[vec[i]] != par.back())
			par.push_back(p[vec[i]]);
	vector<ll> moth;
	vector<bool> is_moth(n, false);
	for (auto i : p)
		if (i != -1)
			is_moth[i] = true;
	for (auto i : vec)
		if (is_moth[i])
			moth.push_back(i);
	if (moth != par)
		bad();

	cout << "Yes\n";
	return d;
}

void solve() {
	cin >> n;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;		
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	col.resize(n, -1);
	for (int i = 0; i < n; i++)
		if (col[i] == -1)
			DFS(i, 0);
	vec.resize(n);
	for (auto &i : vec)
		cin >> i, i--;
	BFS(0);
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}