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
vector<ll> v, dif;
bool viv = false;
ll v0;
ll sum, ans;

void pr() {
	ans = (v0 + sum) / 2;	
	if ((v0 + sum) % 2)
		ans = (v0 + sum + 1) / 2;	


	cout << ans << '\n';
	if (viv) {
		cout << "\t[" << v0 << ' ' << sum << "]: ";
		for (auto i : dif)
			cout << i << ' ';
		cout << '\n';
	}
}

void query() {
	int l, r;
	ll x;
	cin >> l >> r >> x;
	l--, r--;
	if (l == 0)
		v0 += x;
	if (l > 0) {
		if (dif[l - 1] > 0)
			sum -= dif[l - 1];
		dif[l - 1] += x;
		if (dif[l - 1] > 0)
			sum += dif[l - 1];
	}
	if (r < n - 1) {
		if (dif[r] > 0)
			sum -= dif[r];
		dif[r] -= x;
		if (dif[r] > 0)
			sum += dif[r];
	}
	pr();
}

void queries() {
	int q;
	cin >> q;
	while (q--)
		query();
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	v0 = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] > v[i - 1]) {
			sum += v[i] - v[i - 1];
		}
		dif.push_back(v[i] - v[i - 1]);
	}
	pr();
	queries();
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