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


ll n;
bool viv = false;
vector<vector<int>> e;
vector<int> d;

void DFS(int v, int c) {
	d[v] = c;
	for (auto s : e[v])
		if (d[s] == -1)
			DFS(s, c + 1);
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
	d.resize(n, -1);
	DFS(0, 0);

	ll mn = 1, mx = n - 1;

	vector<ll> cnt(2, 0);
	for (int i = 0; i < n; i++)
		if (e[i].size() == 1)
			cnt[d[i] & 1]++;
	if (cnt[0] && cnt[1])
		mn = 3;

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (auto s : e[i])
			if (e[s].size() == 1)
				cnt++;
		mx -= max(cnt - 1, 0);
	}

	cout << mn << ' ' << mx << '\n';

}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}