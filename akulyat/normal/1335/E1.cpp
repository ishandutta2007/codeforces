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
const ll K = 201;


ll n;
bool viv = false;
vector<ll> v;
vector<ll> p[K], all[K];

int cnt(ll val, ll l, ll r) {
	r++;
	return p[val][r] - p[val][l];
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;

	for (int i = 0; i < K; i++) {
		p[i].clear();
		all[i].clear();
		p[i].push_back(0);
		for (int j = 0; j < n; j++) {
			p[i].push_back(p[i].back());
			if (v[j] == i) {
				p[i].back()++;
				all[i].push_back(j);
			}
		}
	}

	int ans = 1;
	for (int i = 0; i < K; i++) {
		int l = 0, r = all[i].size() - 1;
		while (l < r) {
			int lans = 0;
			for (int j = 0; j < 200; j++)
				lans = max(lans, cnt(j, all[i][l] + 1, all[i][r] - 1));
			ans = max(ans, lans + 2 * (l + 1));
			l++, r--;
		}
	}
	cout << ans << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}