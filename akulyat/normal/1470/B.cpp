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
const long long inf = ml + kk; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v, di, dp;
bool viv = false;

vector<ll> erat(int last) {
	di.resize(last + 1, -1);
	vector<ll> res;
	for (int i = 2; i <= last; i++) {
		if (di[i] == -1) {
			res.push_back(i);
			if ((ll)i * i < last)
				for (int j = i * i; j <= last; j += i)
					di[j] = i;
		}
	}
	return res;
}


void prepare() {
	erat(inf);
	dp.resize(inf);
	for (int i = 1; i < inf; i++) {
		if (di[i] != -1) {
			int fr = i / di[i];
			dp[i] = dp[fr];
			if (dp[i] % di[i] == 0)
				dp[i] /= di[i];
			else
				dp[i] *= di[i];
		} else {
			dp[i] = i;
		}
	}
	if (viv) {
		for (int i = 1; i <= 16; i++)
			cout << i << ": " << dp[i] << " - " << di[i] << '\n';
	}
}

void solve() {
	cin >> n;
	v.resize(n);
	unordered_map<int, int> mp, mp2;
	for (auto &i : v)
		cin >> i, i = dp[i], mp[i]++;
	if (viv) {
		cout << "v = ";
		for (auto i : v)
			cout << i << ' ';
		cout << '\n';
	}
	for (auto p : mp)
		if (p.S & 1)
			mp2[p.F] += p.S;
		else
			mp2[1] += p.S;
	int mx = 0;
	for (auto p : mp)
		mx = max(mx, p.S);
	int mx2 = 0;
	for (auto p : mp2)
		mx2 = max(mx2, p.S);

	int q;
	cin >> q;
	while (q--) {
		ll t;
		cin >> t;
		if (t == 0) {
			cout << mx << '\n';
		} else {
			cout << mx2 << '\n';

		}
	}


}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prepare();
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}