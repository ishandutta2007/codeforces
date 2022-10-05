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

ll n, k;
vector<ll> v, ans;
bool viv = false;

ll mex(vector<ll> v) {
	set<ll> s;
	for (int i = 0; i < v.size() + 1; i++)
		s.insert(i);
	for (auto i : v)
		s.erase(i);
	return *s.begin();
}

void make(ll pl, ll val) {
	v[pl] = val;
	ans.push_back(pl);
	// if (viv) {
	// 	cout << "\t Get: ";
	// 	for (auto i : v)
	// 		cout << i << ' ';
	// 	cout << endl;
	// }
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	ans.clear();
	set<ll> have;
	for (int i = 0; i < n; i++) {
		if (v[i] == n || have.count(v[i])) {
			make(i, mex(v));		
		}
		have.insert(v[i]);
	}
	for (int i = 0; i < n; i++)
		if (v[i] != i) {
			make(i, mex(v));
			int k = mex(v);
			while (k != n) {
				make(k, k);
				k = mex(v);
			}
		}

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
	if (viv) {
		cout << "\t\t" << ans.size() << ": ";
		cout << "See: ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}