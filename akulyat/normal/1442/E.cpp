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

int n, ans;
vector<int> v;
vector<vector<int>> e;
bool viv = false;

int step(vector<int> leaf, vector<int> &deg, int col) {
	if (leaf.empty())
		return 0;
	bool need = true;
	vector<int> work, left;
	for (auto i : leaf)
		if (v[i] + col == 3)
			left.push_back(i);
		else
			work.push_back(i);
	while (work.size()) {
		vector<int> work_add;
		for (auto ver : work) {
			deg[ver] = 0;
			for (auto u : e[ver]) {
				if (deg[u] != 0) {
					deg[u]--;
					if (deg[u] == 1) {
						if (v[u] + col == 3)
							left.push_back(u);
						else
							work_add.push_back(u);
					}
				}				
			}
		}
		work = work_add;
	}
	return 1 + step(left, deg, 3 - col);
}

void work(int col) {
	vector<int> deg(n);
	vector<int> leaf;
	for (int i = 0; i < n; i++) {
		deg[i] = e[i].size();
		if (e[i].size() <= 1)
			leaf.push_back(i);
	}
	int lans = step(leaf, deg, col);
	ans = min(ans, lans);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;	
	e.clear();
	e.resize(n);
	for (int i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ans = mod;
	work(1);
	work(2);
	cout << ans << '\n';
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