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

ll n;
vector<vector<int>> kids;
vector<ll> pp;
vector<ll> p, q, cnt;
vector<ll> mx, sum;
vector<bool> used;
bool viv = false;

void DFS(int v) {
	used[v] = true;
	for (auto u : kids[v])
		if (!used[u])
			DFS(u);
	q.push_back(v);
}

void work(int v) {
	if (kids[v].empty()) {
		cnt[v] = 1;
		return void(mx[v] = sum[v] = pp[v]);
	}

	sum[v] = pp[v];
	for (auto u : kids[v]) {
		sum[v] += sum[u];
		cnt[v] += cnt[u];
		mx[v] = max(mx[v], mx[u]);
	}

	ll left = pp[v];
	for (auto u : kids[v]) {
		ll can_max = mx[v] * cnt[u];
		ll can_add = can_max - sum[u];
		left -= min(left, can_add);
	}

	mx[v] += (left + cnt[v] - 1) / cnt[v];

	// cout << v << ": " << cnt[v] << ' ' << sum[v] << ' ' << cnt[v] << endl;
}

void solve() {
	cin >> n;
	kids.resize(n);
	p.resize(n);
	for (int i = 1; i < n; i++) {
		int v;
		cin >> v;
		v--;
		p[i] = v;
		kids[v].push_back(i);
	}
	pp.resize(n);
	for (auto &i : pp)
		cin >> i;
	used.resize(n, false);
	DFS(0);

	sum.resize(n, 0);
	mx.resize(n, 0);
	cnt.resize(n, 0);
	for (auto v : q)
		work(v);

	cout << mx[0];
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