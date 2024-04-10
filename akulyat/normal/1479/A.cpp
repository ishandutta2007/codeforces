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
unordered_map<int, int> mp;

int ask(int pl) {
	if (mp.find(pl) != mp.end())
		return mp[pl];
	cout << "? " << pl + 1 << endl;
	int res;
	cin >> res;
	res--;
	mp[pl] = res;
	return res;
}

void ans(int pl) {
	cout << "! " << pl + 1 << endl;
	exit(0);
}

int good(int pl) {
	int me = ask(pl);
	int l = ask(pl - 1);
	int r = ask(pl + 1);
	if (me < l && me < r && me != -1)
		ans(pl);
}

void solve(int l, int r) {
	if (r - l < 5) {
		for (int i = l; i < r; i++)
			ask(i);
		for (int i = l; i < r; i++)
			good(i);
		assert(false);
	}
	int lm = (2 * l + r) / 3;
	int rm = (l + 2 * r) / 3;
	
	int lv = ask(lm);
	int rv = ask(rm);

	if (lv < rv)
		solve(l, rm);
	else
		solve(lm, r);
}

void solve() {
	cin >> n;
	mp[-1] = mod;
	mp[n] = mod;
	solve(0, n);
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