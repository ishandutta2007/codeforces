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
vector<pll> v;
vector<ll> fr;
vector<ll> tp;
bool viv = false;

void get(ll v) {
	if (v > 2 * n)
		v -= 2 * n;
	if (tp[v] != -1)
		return;
	tp[v] = 1;
	tp[fr[v]] = 0;
	get(fr[v] + n);
}

void solve() {
	cin >> n;
	if (!(n & 1)) {
		cout << "First" << endl;
		for (int i = 0; i < 2 * n; i++)
			cout << 1 + (i % n) << ' ';
		exit(0);
	}
	cout << "Second" << endl;

	v.resize(n, {-1, -1});
	for (int i = 0; i < 2 * n; i++) {
		int tp;
		cin >> tp;
		tp--;
		if (v[tp].F == -1)
			v[tp].F = i + 1;
		else
			v[tp].S = i + 1;
	}
	fr.resize(2 * n + 1);
	for (auto p : v) {
		fr[p.F] = p.S;
		fr[p.S] = p.F;
	}
	tp.resize(2 * n + 1, -1);

	vector<ll> ans;
	for (auto p : v) {
		if (tp[p.F] == 1)
			ans.push_back(p.F);
		if (tp[p.F] == 0)
			ans.push_back(p.S);
		if (tp[p.F] == -1) {
			ans.push_back(p.F);
			get(p.F);
		}
	}
	int sum = 0;
	for (auto i : ans)
		sum += i;
	if (sum & 1) {
		for (auto &i : ans)
			i = fr[i];
	}
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
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