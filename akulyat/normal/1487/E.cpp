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

ll n[4];
vector<ll> v[4];
vector<ll> ans[4];
multiset<ll> sans[4];
vector<vector<ll>> bad[4];
bool viv = false;

void read() {
	for (int i = 0; i < 4; i++)
		cin >> n[i];
	for (int i = 0; i < 4; i++) {
		v[i].resize(n[i]);
		bad[i].resize(n[i]);
		ans[i].resize(n[i]);
		for (auto &val : v[i])
			cin >> val;
	}
	for (int i = 1; i < 4; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			bad[i][b].push_back(a);
		}
	}
}

void del_it(multiset<ll> &a, multiset<ll> &b) {
	for (auto val : b) {
		auto z = a.find(val);
		assert(z != a.end());
		a.erase(z);
	}
}

void ins_it(multiset<ll> &a, multiset<ll> &b) {
	for (auto val : b) {
		a.insert(val);
	}
}

void work() {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < n[i]; k++) {
			ans[i][k] = v[i][k];
			multiset<ll> del;
			for (auto bfr : bad[i][k]) 
				del.insert(ans[i - 1][bfr]);
			if (i != 0) {
				del_it(sans[i - 1], del);
				if (sans[i - 1].empty())
					ans[i][k] += inf;
				else {
					auto z = sans[i - 1].begin();
					ans[i][k] += *z;
				}
				ins_it(sans[i - 1], del);
			}
			// cout << ans[i][k] << ' ';
			sans[i].insert(ans[i][k]);
		}
		// cout << endl;
	}
}

void print() {
	ll ans = *sans[3].begin();
	if (ans >= inf)
		ans = -1;
	cout << ans << '\n';
}

void solve() {
	read();
	work();
	print();
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