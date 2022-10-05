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

ll n, r1, r2, r3, d;
vector<ll> v, v1, v2, p1, p2;
vector<ll> dp;
bool viv = false;

void prepare() {
	p1.resize(n + 1, 0);
	p2.resize(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p1[i + 1] = p1[i] + v1[i];
		p2[i + 1] = p2[i] + v2[i];
	}
}

ll sum1(ll l, ll r) {
	if (l < 0 || r >= v1.size())
		return inf;
	r++;
	return p1[r] - p1[l];
}

ll sum2(ll l, ll r) {
	if (l < 0 || r >= v1.size())
		return inf;
	r++;
	return p2[r] - p2[l];
}

ll get(int pl) {
	if (pl == -1) {
		return -d;
	}
	if (pl < 0 || pl >= dp.size())
		return inf;
	return dp[pl];
}


void solve() {
	cin >> n >> r1 >> r2 >> r3 >> d;
	v.resize(n);
	v1.resize(n);
	v2.resize(n);
	for (auto &i : v)
		cin >> i;
	for (int i = 0; i < n; i++) {
		v1[i] = r3 + min(inf, min(r3, r1) * v[i]);
		v2[i] = min(r2, min(r1, r3) * v[i] + r1) + min(min(r1, r3), r2);
		v2[i] = min(v2[i], v1[i]);
		v1[i] = min(v1[i], v2[i] + 2 * d);
	}
	prepare();
	if (viv) {
		for (auto i : v1)
			cout << i << ' ';
		cout << endl;
		for (auto i : v2)
			cout << i << ' ';
		cout << endl;
	}

	dp.resize(n, inf);
	for (int i = 0; i < n; i++) {
		dp[i] = min(dp[i], get(i - 1) + 1 * d + sum1(i, i));
		dp[i] = min(dp[i], get(i - 2) + 4 * d + sum2(i - 1, i));
	}
	if (viv) {
		for (auto i : dp) {
			cout << i << ' ';
		}
		cout << endl;
	}
	ll ans = dp.back();
	for (int steps = 1; steps <= 1; steps++) {
		int r2 = n - 2;
		int l2 = n - 1 - steps;
		int r1 = l2 - 1;
		if (viv) {
			cout << steps << " steps back" << endl;
			cout << '\t' << " to fill " << r1 + 1 << " need " << get(r1) << endl; 
			cout << '\t' << " to steps need " << (n - 1 - (r1) + steps) * d << endl; 
			cout << '\t' << " to segm [" << l2 << ' ' << r2 << "] need " << sum2(l2, r2) << endl; 
			cout << '\t' << " to segm last need " << v1.back() << endl; 
		}
		ll lans = get(r1) + (n - 1 - (r1) + steps) * d + sum2(l2, r2) + v1.back();
		ans = min(ans, lans);
	}
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