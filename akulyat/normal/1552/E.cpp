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

ll n, k, sz;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	sz = n * k;
	int r = (n + k - 2) / (k - 1);

	v.resize(sz);
	for (auto &i : v)
		cin >> i, i--;

	vector<pll> ans(n, {-1, -1});
	set<int> used;
	for (int it = 0; it < r; it++) {
		set<int> have;
		map<int, int> pl;
		for (int i = 0; i < sz; i++) {
			int val = v[i];
			if (!used.count(val)) {
				if (have.count(val)) {
					int pl1 = pl[val];
					int pl2 = i;
					ans[val] = {pl1, pl2};
					used.insert(val);
					have.clear();
				} else {
					have.insert(val);
					pl[val] = i;
				}
			}
		}
	}
	for (auto p : ans)
		assert(p.F != -1);
	
	for (auto p : ans)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
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