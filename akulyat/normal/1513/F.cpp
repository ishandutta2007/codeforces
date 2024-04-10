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
vector<ll> a, b;
vector<pii> l, r;
bool viv = false;

int get() {
	int ans = 0;

	int nxt = 0;
	int mx = -mod;
	for (auto p : l) {
		int len = p.S - p.F;
		while (nxt < r.size() && r[nxt].F <= p.F)
			mx = max(mx, r[nxt].S), nxt++;

		int res = mx - p.F;
		res = min(res, len);
		ans = max(ans, res);
	}	
	return ans;
}

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;
	for (int i = 0; i < n; i++) 
		if (a[i] < b[i])
			r.push_back({a[i], b[i]});
	for (int i = 0; i < n; i++) 
		if (a[i] > b[i])
			l.push_back({b[i], a[i]});
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());


	int ans1 = get();
	swap(l, r);
	int ans2 = get();
	int ans = max(ans1, ans2);

	ll res = 0;
	for (int i = 0; i < n; i++)
		res += abs(a[i] - b[i]);
	res -= 2ll * ans;
	cout << res << '\n';
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