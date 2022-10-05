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


void solve() {
	cin >> n;
	v.resize(n);
	set<ll> A, B;
	for (auto &i : v) {
		cin >> i;
		if (i & 1)
			B.insert(i);
		else
			A.insert(i);
	}
	sort(v.begin(), v.end());
	ll alice = true;
	ll ac = 0, bc = 0;
	while (v.size()) {
		if ((v.back() & 1) && (!alice)) 
			bc += v.back();
		if (!(v.back() & 1) && (alice)) 
			ac += v.back();
		v.pop_back();
		// cout << ac << ' ' << bc << '\n';
		alice ^= true;
	}	
	if (ac > bc)
		cout << "Alice\n";
	if (ac == bc)
		cout << "Tie\n";
	if (ac < bc)
		cout << "Bob\n";
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