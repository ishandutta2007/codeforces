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
 
ll n, m, len;
vector<vector<ll>> reb, rreb;
vector<ll> p;
vector<pll> d;
bool viv = false;

vector<pll> BFS(ll v) {
	vector<pll> res(n, {mod, 0});
	res[v] = {0, 1};
	vector<ll> st;
	st.push_back(v);
	ll now = 0;
	while (now != st.size()) {
		ll v = st[now];
		for (auto s : rreb[v]) {
			if (res[s].F == res[v].F + 1) {
				res[s].S += res[v].S;
				res[s].S = min(res[s].S, 2ll);
			}
			else {
				if (res[v].F + 1 < res[s].F) {
					res[s] = res[v];
					res[s].S = 1;
					res[s].F++;
					st.push_back(s);
				}
			}
		}
		now++;
	}
	if (viv)
		for (auto p : res)
			cout << p.F <<  ' ' << p.S << endl;
	return res;
}

void solve() {
	cin >> n >> m;
	reb.resize(n);
	rreb.resize(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		reb[a].push_back(b);
		rreb[b].push_back(a);
	}

	cin >> len;
	p.resize(len);
	for (auto &i : p)
		cin >> i, i--;

	d = BFS(p.back());

	ll ans1, ans2;
	ans1 = ans2 = 0;
	for (ll i = 0; i < len - 1; i++) {
		if (viv)
			cout << p[i] << ' ' << d[p[i]].F << ' ' << d[p[i]].S << endl;
		if (d[p[i]].F <= d[p[i + 1]].F)
			ans1++, ans2++;
		else {
			if (d[p[i]].S > 1)
				ans2++;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;

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