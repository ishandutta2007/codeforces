#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, m;
vector<ll> col;
bool viv = false;
vector<vector<int>> e, re;

bool ed(int v, int u) {
	for (auto s : e[v])
		if (s == u)
			return true;
	return false;
}

void work(ll v) {
	col[v] = 1;
	vector<int> a, b;
	for (auto s : e[v])
		if (col[s] == -1)
			a.push_back(s);
	if (a.size() == 2 && a[0] == a[1])
		a.pop_back();	
	if (a.size() == 2) {
		if (ed(a[0], a[1])) {
			col[a[0]] = 1;
			for (auto s : e[a[0]])
				if (col[s] == -1)
					col[s] = 0;
			return;
		}
		if (ed(a[1], a[0])) {
			col[a[1]] = 1;
			for (auto s : e[a[1]])
				if (col[s] == -1)
					col[s] = 0;
			return;
		}
	}	
	for (auto s : a)
		for (auto t : e[s]) {
			b.push_back(t);
		}
	if (a.size() == 0)
		return;
	if (a.size() == 1) {
		col[a[0]] = 0;
		return;
	}
	if (a.size() == 2) {
		for (auto i : a)
			col[i] = 1;
		for (auto i : b)
			col[i] = 0;
	}
}

bool write(int val) {
	vector<ll> ans;
	for (int i = 0; i < n; i++)
		if (col[i] == val)
			ans.push_back(i);
	if (7 * ans.size() > 4 * n)
		return false;
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';	
	return true;
}

bool solve1() {
	col.clear();
	col.resize(n, -2);
	for (int i = n - 1; i >= 0; i--) {
		for (auto s : e[i]) 
			if (col[s] == 1)
				col[i] = -1;
		if (col[i] == -2) {
			for (auto s : e[i])
				if (col[s] == 0)
					col[i] = 1;
			if (col[i] == -2) {
				col[i] = 0;				
			}
		}
	}	
	return write(-1);
}

bool solve3() {
	col.clear();
	col.resize(n, -2);
	for (int i = 0; i < n; i++) {
		for (auto s : re[i]) 
			if (col[s] == 1)
				col[i] = -1;
		if (col[i] == -2) {
			for (auto s : re[i])
				if (col[s] == 0)
					col[i] = 1;
			if (col[i] == -2) {
				col[i] = 0;				
			}
		}
	}	
	return write(-1);
}

bool solve2() {
	col.clear();
	col.resize(n, -1);
	for (int i = 0; i < n; i++) 
		if (col[i] == -1)
			work(i);
	return write(0);
}

void solve() {
	cin >> n >> m;
	e.clear();
	e.resize(n);
	re.clear();
	re.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		re[b].push_back(a);
	}
	if (solve1())
		return;
	if (solve3())
		return;
	assert(false);

}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}