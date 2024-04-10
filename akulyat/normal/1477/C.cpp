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
vector<pll> v;
vector<int> ans;
bool viv = false;

ll scalar(pll v1, pll v2) {
	return v1.F * v2.F + v1.S * v2.S;
}

void dec(pll &a, pll b) {
	a.F -= b.F;
	a.S -= b.S;
}

bool good(pll a, pll o, pll b) {
	pll v1 = a;
	pll v2 = b;
	dec(v1, o);
	dec(v2, o);
	if (viv)
		cout << "see: " << scalar(v1, v2) << '\n';
	return scalar(v1, v2) > 0;
}

bool good(deque<pll> p) {
	for (int i = 2; i < p.size(); i++)
		if (!good(p[i - 2], p[i - 1], p[i]))
			return false;
	return true;
}

void add(vector<int> &ans, int add) {
	int sz = ans.size();
	if (good(v[ans[sz - 2]], v[ans[sz - 1]], v[add])) {
		ans.push_back(add);
		return;
	}
	deque<int> pref, suf;
	for (auto i : ans)
		pref.push_back(i);
	while (true) {
		assert(pref.size());
		suf.push_front(pref.back());
		pref.pop_back();

		deque<pll> mid;
		mid.push_back(v[add]);
		for (int i = 0; i < min(2, (int)suf.size()); i++)
			mid.push_back(v[suf[i]]);
		for (int i = 0; i < min(2, (int)pref.size()); i++)
			mid.push_front(v[pref[pref.size() - 1 - i]]);

		if (good(mid)) {
			ans.clear();
			for (auto i : pref)
				ans.push_back(i);
			ans.push_back(add);
			for (auto i : suf)
				ans.push_back(i);
			return;
		}
	}
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;
	ans.push_back(0);
	ans.push_back(1);
	for (int i = 2; i < n; i++) {
		add(ans, i);
	}
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
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