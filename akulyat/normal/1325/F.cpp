#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n, m, want;
vector<vector<ll>> e;
vector<ll> d, p;
bool viv = false;

void cicle(vector<int> ans) {
	cout << 2 << endl;
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i + 1 << ' ';	
	exit(0);
}

void DSU(vector<int> ans) {
	while (ans.size() > want)
		ans.pop_back();
	cout << 1 << endl;
	for (auto i : ans)
		cout << i + 1 << ' ';	
	exit(0);
}

void DFS(ll v, ll c) {
	d[v] = c;
	for (auto s : e[v])
		if (d[s] == -1)
			p[s] = v, DFS(s, c + 1);
}

void solve() {
	cin >> n >> m;
	e.resize(n);	
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d.resize(n, -1);
	int root = 0;
	while (e[root].size() == 1)
		root++;
	p.resize(n, root);
	DFS(root, 0);

	want = 1;
	while (want * want < n)
		want++;
	for (int v = 0; v < n; v++) {
		for (auto s : e[v])
			if (d[s] < d[v] && p[v] != s && d[v] - d[s] + 1 >= want) {
				vector<int> ans;
				int ver = v;
				while (ver != s)
					ans.push_back(ver), ver = p[ver];
				ans.push_back(ver);
				cicle(ans);
			}
	}

	vector<int> lst;
	for (int i = 0; i < n; i++)
		if (e[i].size() == 1)
			lst.push_back(1);

	vector<vector<int>> vert(want - 1);
	for (int i = 0; i < n; i++)
		vert[d[i] % vert.size()].push_back(i);
	for (int i = 0; i < vert.size(); i++) {
		if (vert[i].size() >= want)
			DSU(vert[i]);
	}
	cout << "Impossible\n";
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();






	return 0;
}