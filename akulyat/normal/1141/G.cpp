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

ll n, k, ans;
map<pii, int> mp;
vector<vector<int>> e;
vector<bool> used;
vector<set<int>> bad;
bool viv = false;

void DFS(int v) {
	used[v] = true;
	int nxt = 0;
	for (auto s : e[v]) 
		if (!used[s]) {
			while (bad[v].count(nxt))
				nxt++;
			if (e[v].size() > ans)
				nxt = 0;
			mp[{v, s}] = nxt;
			mp[{s, v}] = nxt;
			bad[v].insert(nxt);
			bad[s].insert(nxt);
			DFS(s);
			nxt++;
		}
}


void solve() {
	cin >> n >> k;
	e.resize(n);
	vector<int> sz;
	vector<pii> all;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
		all.push_back({a, b});
	}
	for (int i = 0; i < n; i++)
		sz.push_back(i);
	sort(sz.rbegin(), sz.rend(), [&](int a, int b) {
		return e[a].size() < e[b].size();
	});
	// for (auto i : sz)
	// 	cout << e[i].size() << ' ';
	// cout << '\n';
	ans = e[sz[k]].size();
	cout << ans << '\n';

	used.resize(n, false);
	bad.resize(n);
	DFS(0);

	vector<int> ans;
	for (auto p : all)
		ans.push_back(mp[p]);
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
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