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

ll n, m, x;
vector<pll> v;
bool viv = false;


void solve() {
	cin >> n >> m >> x;
	v.resize(n);
	for (auto &i : v)
		cin >> i.F;
	for (int i = 0; i < n; i++)
		v[i].S = i;
	sort(v.rbegin(), v.rend());

	set<pii> s;
	vector<int> ans(n, -1);
	for (int i = 0; i < m; i++) {
		ans[v[i].S] = i;
		s.insert({v[i].F, i});
	}

	for (int i = m; i < n; i++) {
		auto p = *s.begin();
		s.erase(p);
		ans[v[i].S] = p.S;
		p.F += v[i].F;
		s.insert(p);
	}

	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
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