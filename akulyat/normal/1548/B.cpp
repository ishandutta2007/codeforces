#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;
int ans = 1;

pll add(pll a, ll val) {
	ll d1 = a.S;
	ll d2 = abs(a.F - val);
	a.S = __gcd(d1, d2);
	return a;
}

pll add2(pll a, pll b) {
	ll d1 = a.S;
	ll d2 = abs(a.F - b.F);
	ll d3 = b.S;
	a.S = __gcd(d1, __gcd(d2, d3));
	return a;
}

struct line {
	vector<pll> pref, suf;
	vector<ll> vals;
	int sz;

	line() {}

	line(ll val) {
		sz = 1;
		pref = suf = vector<pll>(1, {val, 0});
		vals = {val};
		ans = max(ans, 1);
	}

	line merge(line l, line r) {
		sz = l.sz + r.sz;

		for (auto i : l.vals)
			vals.push_back(i);
		for (auto i : r.vals)
			vals.push_back(i);

		for (int i = 0; i < l.sz; i++) {
			pref.push_back(l.pref[i]);
		}
		for (int i = 0; i < r.sz; i++) {
			pref.push_back(add(pref.back(), r.vals[i]));
		}

		for (int i = 0; i < r.sz; i++) {
			suf.push_back(r.suf[i]);
		}
		reverse(suf.begin(), suf.end());
		for (int i = l.sz - 1; i >= 0; i--) {
			suf.push_back(add(suf.back(), l.vals[i]));
		}
		reverse(suf.begin(), suf.end());

		for (int i = l.sz - 1; i >= 0; i--) {
			int lu = l.sz - i;

			int lb = 0;
			int rb = r.sz + 1;
			while (lb + 1 != rb) {
				int mb = lb + rb >> 1;

				auto lg = l.suf[i];
				auto rg = r.pref[mb - 1];

				int ru = mb;

				auto mg = add2(lg, rg);
				if (mg.S != 1) {
					lb = mb;
					ans = max(ans, lu + ru);

					if (viv) {
						cout << "\tvals = ";
						for (auto i : vals)
							cout << i << ' ';
						cout << endl;
						cout << "\tuse: " << lu << " of " << l.sz << " and " << ru << " of " << r.sz << endl;
						cout << "\tget: " << mg.F << ' ' << mg.S << endl;
					}
				} else {
					rb = mb;
				}
			}
		}
		if (viv) {
			cout << "pref = ";
			for (auto p : pref)
				cout << "{" << p.F << ' ' << p.S << "}, ";
			cout << endl;
		}

		for (int i = 0; i < sz; i++) {
			if (pref[i].S != 1)
				ans = max(ans, i + 1);
		}
		for (int i = sz - 1; i >= 0; i--) {
			if (suf[i].S != 1)
				ans = max(ans, sz - i);
		}

		return *this;
	}
};

line work(int l, int r) {
	if (l + 1 == r)
		return line(v[l]);

	int m = l + r >> 1;
	line res;
	return res.merge(work(l, m), work(m, r));
}


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ans = 0;
	work(0, n);	
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