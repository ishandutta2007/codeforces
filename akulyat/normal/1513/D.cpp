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

ll n, p;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> p;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<pii> tos;
	for (int i = 0; i < n; i++)
		tos.push_back({v[i], i});
	sort(tos.begin(), tos.end());

	ll ans = 0, cnt = 0;
	vector<bool> used(n - 1, false);
	for (auto pr : tos) 
		if (pr.F < p) {
			int pl = pr.S;
			int l = pl - 1, r = pl + 1;
			while (l >= 0     && !used[l] && !(v[l] % v[pl]))
				used[l] = true, l--, ans += pr.F;
			while (r <= n - 1 && !used[r - 1] && !(v[r] % v[pl]))
				used[r - 1] = true, r++, ans += pr.F;
			// cout << "see: [" << l + 1 << " |" << pl << "| " << r - 1 << "]" << endl;
		}
	for (auto i : used)
		if (!i)
			ans += p;
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