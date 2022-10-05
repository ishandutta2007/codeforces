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
vector<ll> v;
bool viv = false;

int solver(ll a, ll b) {
	if (viv)
		cout << "solver(" << a << ' ' << b << ")" << endl;
	vector<int> val;
	for (auto i : v)
		val.push_back(0 + (i == a) - (i == b));

	vector<int> prev(2 * n + 1, mod);
	vector<int>p(n + 1, -1);
	p[0] = n, prev[n] = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + val[i];
		res = max(res, i + 1 - prev[p[i + 1]]);
		prev[p[i + 1]] = min(prev[p[i + 1]], i + 1);
	}
	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	bool dif = false;
	for (int i = 1; i < n; i++)
		if (v[i] != v[i - 1])
			dif = true;
	map<int, int> cnt;	
	for (auto i : v)
		cnt[i]++;
	int mpop = 0;
	for (auto p : cnt)
		mpop = max(mpop, p.S);
	vector<int> pop;
	for (auto p: cnt)
		if (p.S == mpop)
			pop.push_back(p.F);
	if (pop.size() > 1) {
		cout << n << '\n';
		return;
	}
	int ans = 0;
	for (auto p : cnt)
		if (p.F != pop[0])
			ans = max(ans, solver(pop[0], p.F));
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