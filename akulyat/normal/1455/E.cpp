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
vector<pll> v;
bool viv = false;

ll dist(pll a, pll b) {
	return abs(a.F - b.F) + abs(a.S - b.S);
}

bool inter(pll a, pll b) {
	if (a.S < b.F)
		return false;
	if (b.S < a.F)
		return false;
	return true;
}
void work(pll p, ll sh) {
	if (viv) {
		cout << p.F << ' ' << p.S << endl;
		cout << p.F + sh << ' ' << p.S << endl;
		cout << p.F << ' ' << p.S + sh << endl;
		cout << p.F + sh << ' ' << p.S + sh << endl;
		for (auto pt : v)
			cout << "\t" << pt.F << ' ' << pt.S << endl;
	}
	ll res = 0;
	res += dist(v[0], p);
	res += dist(v[1], {p.F + sh, p.S});
	res += dist(v[2], {p.F, p.S + sh});
	res += dist(v[3], {p.F + sh, p.S + sh});
	ans = min(ans, res);	
}

void work(ll x, ll y) {
	pll p = {x, y};
	ll a = v[1].F - x;
	ll b = v[2].S - y;
	if (a > b)
		swap(a, b);

	ll c = v[3].F - x;
	ll d = v[3].S - y;
	if (c > d)
		swap(c, d);

	if (inter({a, b}, {c, d})) {
		ll sh = max(a, c);
		work(p, sh);
		return;
	} 
	ll pl = 0;
	if (b < c) 
		pl = (2 * b + c) / 3;
	if (d < a) 
		pl = (d + 2 * a) / 3;
	for (int i = -10; i < 10; i++)
		work(p, pl + i);
}

void work() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			work(v[i].F, v[j].S);
		}
	}	
}

void solve() {
	n = 4;
	ans = inf;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;
	for (int i = 0; i < 24; i++) {
		work();
		next_permutation(v.begin(), v.end());
	}
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