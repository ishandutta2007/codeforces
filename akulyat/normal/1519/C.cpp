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
vector<ll> v, p;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	p.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	for (auto &i : p)
		cin >> i;

	vector<vector<ll>> u(n), pr(n);
	for (int i = 0; i < n; i++)
		u[v[i]].push_back(p[i]);
	for (int i = 0; i < n; i++) {
		sort(u[i].rbegin(), u[i].rend());
	}

	sort(u.begin(), u.end(), [](const vector<ll> &a, const vector<ll> &b) {
		return a.size() > b.size();
	});
	for (int i = 0; i < n; i++) {
		pr[i].push_back(0);
		for (auto val : u[i])
			pr[i].push_back(pr[i].back() + val);
	}


	// for (int i = 0; i < n; i++)
	// 	cout << '\t' << u[i].size() << " - " << pr[i].size() << '\n';
	for (int k = 1; k <= n; k++) {
		ll ans = 0;
		while (u.size() && u.back().size() < k) {
			u.pop_back();
			pr.pop_back();
		}
		for (int j = 0; j < u.size(); j++) {
			int sz = u[j].size() / k * k;
			// cout << "\t" << j << ": " << sz << '\n';
			// if (sz > pr[j].size()) {
			// 	cout << "BAD" << endl;
			// 	cout << k << ' ' << u[j].size() << ' ' << sz << ' ' << pr[j].size() << endl;
			// 	exit(1);
			// }

			ans += pr[j][sz];
		}
		cout << ans << '\n';
	}
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