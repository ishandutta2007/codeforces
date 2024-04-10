#include <bits/stdc++.h>
 
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
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, m;
bool viv = false;
vector<vector<ll>> v;

bool can(ll val, bool wr = false) {
	vector<vector<ll>> tp;
	tp.resize(256);
	ll cnt = 0;
	for (auto vec : v) {
		ll res = 0;
		for (ll i = 0; i < m; i++) {
			if (vec[i] < val)
				res |= (1 << i);			
		}
		tp[res].push_back(cnt);
		cnt++;
	}

	pll pr = {-1, -1};

	for (ll i = 0; i < 256; i++) {
		for (ll j = 0; j < 256; j++)
//			if (i != j) {
				if ((i & j) == 0 && tp[i].size() && tp[j].size()) {
					pr.F = tp[i][0] + 1;
					pr.S = tp[j][0] + 1;
				}
//			}
	}
	if (tp[0].size() >= 2) {
		pr = {tp[0][0] + 1, tp[0][1] + 1};
	}

	if (wr) {
//		cout << val << endl;
		cout << pr.F << ' ' << pr.S;
		exit(0);
	}

	if (pr.F != -1)
		return true;
	return false;
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		i.resize(m);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll a;
			cin >> a;
			v[i][j] = a;			
		}
	}

	ll l = 0;
	ll r = inf;
	while (l + 1 < r) {
		ll mi = l + r >> 1;
		if (can(mi))
			l = mi;
		else
			r = mi;
	}
	can(l, true);
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
    	solve();


    return 0;
}