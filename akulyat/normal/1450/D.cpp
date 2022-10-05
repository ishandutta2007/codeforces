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
vector<pll> seg;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	seg.clear();
	seg.resize(n);
	vector<pll> st;
	st.push_back({-1, -1});
	for (int i = 0; i < n; i++) {
		while (st.back().F > v[i])
			st.pop_back();
		seg[i].F = st.back().S;
		st.push_back({v[i], i});
	}
	st.clear();
	st.push_back({-1, n});
	for (int i = n - 1; i >= 0; i--) {
		while (st.back().F >= v[i])
			st.pop_back();
		seg[i].S = st.back().S;
		st.push_back({v[i], i});
	}
	st.clear();

	for (int i = 0; i < n; i++) {
		seg[i].F = (i - seg[i].F - 1);
		seg[i].S = (seg[i].S - i - 1);
	}
	if (viv) {
		for (auto p : seg)
			cout << p.F << ' ' << p.S << '\n';	
	}

	vector<vector<pll>> sob(n + 3);

	for (int i = 0; i < n; i++) {
		sob[1].push_back({1, v[i]});
		sob[2].push_back({-1, v[i]});
		ll l = seg[i].F;
		ll r = seg[i].S;
		if (l != 0 && r != 0) {
			sob[l + r + 1].push_back({1, v[i]});
			sob[l + r + 2].push_back({-1, v[i]});
		} else {
			if (l != 0 || r != 0) {
				sob[2].push_back({1, v[i]});
				sob[l + r + 2].push_back({-1, v[i]});
			}
		}
	}
	vector<ll> cnt(n, 0);
	string ans(n, '0');
	ll big = 0;
	ll sum = 0;
	ll mx_need = n - 1;
	ll too_big = 0;
	for (int i = 1; i <= n; i++) {
		for (auto p : sob[i]) {
			if (p.F == 1) {
				cnt[p.S]++;
				if (mx_need >= p.S)
					sum++;
				else
					too_big++;
				big += (cnt[p.S] == 2);
			} else {
				cnt[p.S]--;
				if (mx_need >= p.S)
					sum--;
				else
					too_big--;
				big -= (cnt[p.S] == 1);
			}
		}
		if (viv) {
			cout << "\t" << sum << ' ' << big << ' ' << mx_need;
			cout << "\t\t";
			for (auto i : cnt)
				cout << i << ' ';
			cout << endl;
		}
		if (sum == (n + 1 - i) && (big == 0) && (too_big == 0))
			ans[i - 1] = '1';
		sum -= cnt[mx_need];
		too_big += cnt[mx_need];
		mx_need--;
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