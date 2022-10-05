#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<ll> v;
map<pll, ll> gg;
bool viv = false;

ll get(ll p1, ll p2) {
	cout << "? ";
	cout << p1 + 1 << ' ' << p2 + 1 << endl;
	ll res = 0;
	cin >> res;
	gg[{p1, p2}] = res;
	gg[{p2, p1}] = res;
	return res;
}

ll cnt(ll val) {
	ll res = 0;
	for (int i = 0; i < 15; i++) {
		res += (val & 1);
		val >>= 1;		
	}
	return res;
}

pll sol(vector<ll> pl) {
	if (pl.size() == 1)
		return {0, pl[0]};
	ll n = pl.size();
	vector<pll> ch(11, {-1, -1});	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll o = get(pl[i], pl[j]);
			ll fo = o;
			for (int b = 0; b < 11; b++) {
				if (!(fo & 1))
					ch[b] = {pl[i], pl[j]};
				fo >>= 1;
			}
		}
	}
	for (auto i : ch)
		assert(i.F != -1);

	vector<pair<ll, pll>> lans;
	for (int i = 0; i < n; i++) {
		ll p = pl[i];
		ll me = 0;
		for (int b = 10; b >= 0; b--) {
			me <<= 1;
			ll fr = ch[b].F;
			if (fr == p)
				fr = ch[b].S;
			ll an = gg[{p, fr}];

			an >>= b;
			an &= 1;
			me += an;
		}
		lans.push_back({cnt(me), {me, pl[i]}});
	}
	sort(lans.begin(), lans.end());
	if (viv) {
		for (auto i : lans) {
			cout << i.F << ' ' << i.S.F << ' ' << i.S.S << endl;
		}
	}
	return lans[0].S;
}


void solve() {
	cin >> n;	

	ll sz = 12;



	vector<ll> p;
	for (int i = 0; i < n; i++)
		p.push_back(i);
	random_shuffle(p.begin(), p.end());
	while (p.size() > sz)
		p.pop_back();
	pll sm = sol(p);
	if (viv)
		cout << "Good " << sm.F << endl;

	ll z = -1;
	if (sm.F == 0)
		z = sm.S;
	else {
		vector<ll> cand;
		for (int i = 0; i < n; i++)
			if (i != sm.S)
				if (sm.F == get(sm.S, i))
					cand.push_back(i);
		pll sm2 = sol(cand);
		assert(sm2.F == 0);
		z = sm2.S;
	}

	vector<ll> ans(n, 0);
	for (int i = 0; i < n; i++)
		if (i != z)
			ans[i] = get(i, z);
	cout << "! ";
	for (auto i : ans)
		cout << i << ' ';

}

int main() {
	// viv = true;
	srand(time(0));
	// srand(169);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}