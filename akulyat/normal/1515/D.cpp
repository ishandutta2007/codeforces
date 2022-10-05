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

ll n, l, r;
int ans;
vector<ll> v, vl, vr;
bool viv = false;

int work(multiset<int> s) {
	set<int> ss;
	for (auto i : s) {
		ss.insert(i);
	}
	ll res = 0;
	for (auto v : ss) {
		int cnt = s.count(v);
		// ans += cnt / 2;
		res += (cnt & 1);
	}
	return res;
}

void solve() {
	cin >> n >> l >> r;
	v.resize(n);
	vl.resize(l);
	vr.resize(r);
	for (auto &i : v)
		cin >> i, i--;
	ans = 0;

	for (int i = 0; i < l; i++)
		vl[i] = v[i];
	for (int i = 0; i < r; i++)
		vr[i] = v[l + i];

	multiset<int> sl, sr;
	for (auto i : vl)
		sl.insert(i);

	for (auto i : vr) {
		if (sl.count(i)) {
			sl.erase(sl.find(i));
		} else {
			sr.insert(i);
		}
	}

	int szl = work(sl);
	int szr = work(sr);
	int pl = sl.size() - szl;
	int pr = sr.size() - szr;

	int sz = min(szl, szr);
	ans += sz;
	szl -= sz;
	szr -= sz;

	while (szl >= 2 && pr >= 2) {
		szl -= 2;
		pr -= 2;
		ans += 2;
	}
	while (szr >= 2 && pl >= 2) {
		szr -= 2;
		pl -= 2;
		ans += 2;
	}

	ans += pl / 2;
	ans += pr / 2;
	ans += szl;
	ans += szr;

	// cout << "\t" << szl << ' ' << szr << '\n';

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