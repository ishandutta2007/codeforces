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

ll n, ans;
vector<ll> v;
vector<pll> pr;
vector<ll> p;
bool viv = false;

void work(ll can) {
	if (viv)
		cout << "work " << can << endl;
	ll sum = p.back();
	ll add = p[can];
	if (viv)
		cout << "Was " << add;
	if (can * 2 + 1 == n) {
		bool good = false;
		for (int i = 0; i < can; i++)		
			if (!(pr[i].S & 1))
				good = true;
		if (!good) {
			add -= pr[can - 1].F;
			add += pr[can].F;
		}
	}
	if (viv)
		cout << " become " << add << endl;
	sum -= 2 * add;
	ans = max(ans, sum);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	if (n == 1) {
		cout << v[0] << '\n';
		exit(0);
	}
	for (int i = 0; i < n; i++)
		pr.push_back({v[i], i});
	sort(pr.begin(), pr.end());
	p.push_back(0);
	ans = -inf;
	for (auto it : pr)
		p.push_back(p.back() + it.F);

	ll can = (4 - (n % 3)) % 3;
	while (can <= n)
		work(can), can += 3;
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