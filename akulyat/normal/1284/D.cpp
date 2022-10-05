#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<pll, pll>   ppll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ppll> v;
bool viv = false;

bool inter(pll a, pll b) {
	if (a.S < b.F || b.S < a.F)
		return false;
	return true;
}

void bad() {
	cout << "NO\n";
	exit(0);
}

void check() {
	sort(v.begin(), v.end());
	multiset<ppll> a;
	multiset<ppll> b;
	for (int i = 0; i < n; i++) {
		auto p = v[i];
		while (a.size() && (*a.begin()).F.F < p.F.F) {
			auto pf1 = *a.begin();
			a.erase(a.begin());
			auto pp = pf1;
			swap(pp.F.F, pp.F.S);
			auto pfp2 = pp;
			swap(pfp2.F, pfp2.S);
			swap(pfp2.F.F, pfp2.F.S);
			b.erase(pfp2);
		}
		// cout << "a\n";
		// for (auto pp : a) 
		// 	cout << "\t" << pp.F.F << ' ' << pp.F.S << ' ' << pp.S.F << ' ' << pp.S.S << endl;
		// cout << "b\n";
		// for (auto pp : b) 
		// 	cout << "\t" << pp.F.F << ' ' << pp.F.S << ' ' << pp.S.F << ' ' << pp.S.S << endl;
		if (b.size()) {
			auto fr = *b.begin();
			auto pr = fr.F;
			swap(pr.F, pr.S);
			if (!inter(pr, p.S))
				bad();
		}


		auto fp1 = p;
		swap(fp1.F.F, fp1.F.S);
		a.insert(fp1);
		auto fp2 = p;
		swap(fp2.F, fp2.S);
		swap(fp2.F.F, fp2.F.S);
		b.insert(fp2);
	}
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v) {
		cin >> p.F.F >> p.F.S;
		cin >> p.S.F >> p.S.S;
	}
	check();
	for (auto &p : v)
		swap(p.F, p.S);
	check();
	cout << "YES\n";
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