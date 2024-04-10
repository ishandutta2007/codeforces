#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
#define F first
#define S second
typedef int   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
 

ll n;
string s, so, sc;
vector<ll> cnto, cntc;
vector<vector<ll>> dpo, dpc;
bool viv = false;

ll balo(ll l, ll r) {
	r++;
	return cnto[r] - cnto[l];
}

ll balc(ll l, ll r) {
	r++;
	return cntc[r] - cntc[l];
}

void prepare() {
	cnto.push_back(0);
	for (ll i = 0; i < n; i++) {
		cnto.push_back(cnto.back());
		if (so[i] == '(')
			cnto.back()++;
		else
			cnto.back()--;
	}
	cntc.push_back(0);
	for (ll i = 0; i < n; i++) {
		cntc.push_back(cntc.back());
		if (sc[i] == '(')
			cntc.back()++;
		else
			cntc.back()--;
	}

	dpo.resize(n);
	dpc.resize(n);
	for (auto &l : dpo)
		l.resize(n);
	for (auto &l : dpc)
		l.resize(n);

	for (ll i = 0; i < n; i++) {
		dpo[i][i] = balo(i, i);
		dpc[i][i] = balc(i, i);
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			dpo[i][j] = min(dpo[i][j - 1], balo(i, j));
			dpc[i][j] = min(dpc[i][j - 1], balc(i, j));
		}
	}
}

bool check(ll lo, ll ro, ll lc, ll rc) {
	if (lo <= ro && dpo[lo][ro] < 0)
		return false;
	if (lc <= rc && balo(lo, ro) + dpc[lc][rc] < 0)
		return false;
	return true;
}

void solve() {
	cin >> s;
	n = s.size();

	so = s, sc = s;
	for (auto &i : so)
		if (i == '?')
			i = '(';
	for (auto &i : sc)
		if (i == '?')
			i = ')';
	prepare();


	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		vector<ll> q;
		ll o, c;
		o = c = 0;
		for (ll j = i; j < n; j++) {
			if (s[j] == '?')
				q.push_back(j);
			if (s[j] == '(')
				o++;
			if (s[j] == ')')
				c++;
			ll len = j - i + 1;
			if (max(o, c) * 2 <= len && !(len & 1)) {
				ll need = len / 2 - o;
				ll o_l, o_r, c_l, c_r;
				o_l = i;
				o_r = o_l - 1;
				c_r = j;
				if (need) {	
					o_r = q[need - 1];
				}
				c_l = o_r + 1;

				if (check(o_l, o_r, c_l, c_r)) 
					ans++;
			}
		}
	}
	cout << ans << endl;
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