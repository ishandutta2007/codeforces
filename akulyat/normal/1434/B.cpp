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
bool viv = false;


void bad() {
	cout << "NO\n";
	exit(0);
}

void good(){
	cout << "YES\n";
}

void check(vector<pll> all) {
	set<ll> s;
	for (int i = 0; i < all.size(); i++) {
		if (all[i].F) {
			s.insert(all[i].S);
			// cout << "Add " << all[i].S << endl;
		} else {
			int want = *s.begin();
			s.erase(want);
			// cout << " cmp " << want << ' ' << all[i].S << endl;
			if (want != all[i].S)
				bad();
		}
	}
	good();
	for (auto p : all)
		if (p.F)
			cout << p.S + 1 << ' ';
}

void solve() {
	cin >> n;
	vector<ll> last;
	vector<pll> all;
	for (int i = 0; i < 2 * n; i++) {
		string s;
		cin >> s;
		if (s[0] == '+') {
			last.push_back(i);
			all.push_back({1, -1});
		}
		else {
			int val;
			cin >> val;
			val--;
			if (last.empty())
				bad();
			int pl = last.back();
			last.pop_back();
			all[pl].S = val;
			all.push_back({0, val});
		}
	}
	// for (auto p : all)
	// 	cout << p.F << ' ' << p.S << endl;
	check(all);
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