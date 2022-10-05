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

ll n, m, k;
vector<vector<pii>> e;
vector<vector<pii>> have;
vector<bool> b;
bool viv = false;

void build(int v) {
	for (auto &p : e[v])
		swap(p.F, p.S);
	sort(e[v].begin(), e[v].end());
	for (auto &p : e[v])
		swap(p.F, p.S);
	int ed = e[v].size() - 1;
	for (int i = 0; i < e[v].size(); i++) {
		int u = e[v][i].F;
		have[u].push_back({i, ed});
	}
}

_hash(int a, int b, int c, int d) {
	return a + k * (b + k * (c + k * (d)));
}

void ban(int v) {
	multiset<pii> hs;
	for (auto pr: have[v])
		if (hs.count(pr) < 2)
			hs.insert(pr);
	vector<pii> hv;
	for (auto p : hs)
		hv.push_back(p);
	if (viv) {
		cout << v << " have: ";
		for (auto p : hv)
			cout << p.F << ' ' << p.S << ", ";
		cout << endl;	
	}
	for (int i = 0; i < hv.size(); i++) {
		for (int j = 0; j < hv.size(); j++) {
			if (i != j) {
				int mask = _hash(hv[i].F, hv[i].S, hv[j].F, hv[j].S);
				if (viv)
					cout << "\tbroke: " << hv[i].F << ' ' << hv[i].S << ' ' << hv[j].F << ' ' << hv[j].S << endl;
				b[mask] = true;
			}
		}
	}
}

void build() {
	have.resize(n);
	for (int i = 0; i < n; i++)
		build(i);
	b.resize(k * k * k * k, false);
	for (int i = 0; i < n; i++)
		ban(i);
}

bool check(vector<int> &perm) {
	vector<int> res(k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < i; j++)
			if (perm[j] > perm[i])
				res[i]++;
	}
	if (viv) {
		cout << "res = ";
		for (auto i : res)
			cout << i << ' ';
		cout << endl;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			int mask = _hash(res[i], i, res[j], j);
			if (b[mask]) {
				if (viv)
					cout << "\tban by: " << res[i] << ' ' << i << ' ' << res[j] << ' ' << j << endl;
				return false;
			}
		}
	}
	return true;
}

void solve() {
	cin >> n >> m >> k;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		e[a].push_back({b, c});
	}
	build();
	vector<int> perm;
	for (int i = 0; i < k; i++)
		perm.push_back(i);
	int ans = 0;
	ans += check(perm);
	while (next_permutation(perm.begin(), perm.end())) {
		ans += check(perm);
	}
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