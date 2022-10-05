#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, k;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n >> k;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<pll> vv;
	for (int i = 0; i < n / 2; i++) {
		vv.push_back({v[i], v[n - 1 - i]});
	}
	for (auto &p: vv)
		if (p.F > p.S)
			swap(p.F, p.S);

	vector<ll> b(2 * k + 10);
	n /= 2;
	for (int i = 0; i < n; i++) {
		int mi = vv[i].F + 1;
		int ma = vv[i].S + k;
		b[mi]++;
		b[ma + 1]--;
	}
	if (viv) {
		for (auto i : b)
			cout << i << ' ';
		cout << endl;
	}
	ll sum = 0;
	for (int i = 0; i < b.size(); i++) {
		sum += b[i];
		b[i] = sum;
	}
	if (viv) {
		for (auto i : b)
			cout << i << ' ';
		cout << endl;
	}
	for (auto p : vv)
		b[p.F + p.S]++;
	if (viv) {
		for (auto i : b)
			cout << i << ' ';
		cout << endl;
	}
	ll ans = mod;
	for (int i = 2; i <= 2 * k; i++)
		ans = min(ans, 2 * n - b[i]);
	cout << ans << '\n';
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}