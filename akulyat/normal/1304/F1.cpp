#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
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
 
ll n, m, k;
vector<vector<ll>> v, p;
bool viv = false;

void prepare() {
	p.resize(v.size() + 1);
	for (auto &l : p)
		l.resize(v[0].size() + 1);
	for (ll i = 1; i < p.size(); i++) {
		for (ll j = 1; j < p[i].size(); j++)
			p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + v[i - 1][j - 1];
	}
}

ll sum(ll i, ll j) {
	i++, j++;
	ll res = p[i][j];
	res -= p[i - 2][j];
	res -= p[i][j - k];
	res += p[i - 2][j - k];
	return res;
}

ll lsum(ll i, ll j1, ll j2) {
	if (j1 > j2)
		return 0;
	i++, j2++;
	ll res = 0;
	res += p[i][j2];
	res -= p[i][j1];
	res -= p[i - 1][j2];
	res += p[i - 1][j1];
	return res;
}

void solve() {
	cin >> n >> m >> k;
	v.resize(n + 1);
	for (ll i = 0; i < n; i++) {
		v[i].resize(m);
		for (auto &val : v[i])
			cin >> val;
	}
	for (ll i = 0; i < m; i++)
		v.back().push_back(0);
	prepare();

	vector<vector<ll>> ans, pref, suf;
	ans.resize(n + 1);
	pref.resize(n + 1);
	suf.resize(n + 1);
	for (auto &l : ans)
		l.resize(m - k + 1);
	for (auto &l : pref)
		l.resize(m - k + 2);
	for (auto &l : suf)
		l.resize(m - k + 2);
	ll len = m - k + 1;
	ll gans = 0;
	for (ll i = 1; i < n + 1; i++) {
		for (ll j = 0; j < len; j++) {
			ll me = sum(i, j + k - 1);
			ll ans1 = pref[i - 1][max(0ll, j - k + 1)];
			ll ans2 = suf[i - 1][min(len, j + k + 1)];
			ll res = max(ans1, ans2) + me;
			for (ll u = max(0ll, j - k); u <= min(len - 1, j + k); u++) {
				ll lres = ans[i - 1][u];
				lres += me;
				lres -= lsum(i - 1, max(j, u), min(j + k - 1, u + k - 1));
				if (viv)
					cout << "See " << ans[i - 1][u] << ' ' << me << ' ' << lsum(i - 1, max(j, u), min(j + k - 1, u + k - 1)) << endl;
				res = max(lres, res);
			}
			ans[i][j] = res;
			if (viv)
				cout << i << ' ' << j << ' ' << ans[i][j] << endl;
			gans = max(gans, res);
		}
		for (ll j = 1; j < len + 1; j++)
			pref[i][j] = max(pref[i][j - 1], ans[i][j - 1]);
		for (ll j = len - 1; j >= 0; j--)
			suf[i][j] = max(suf[i][j + 1], ans[i][j]);
	}
	cout << gans << endl;
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}