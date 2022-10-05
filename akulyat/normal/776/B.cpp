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
bool viv = false;

vector<ll> erat(ll n) {
	vector<bool> pr(n + 1, true);
	vector<ll> res;
	for (ll i = 2; i < n; i++) {
		if (pr[i])
			res.push_back(i);
		for (ll j = i * i; j < n; j += i)
			pr[j] = false;		
	}
	return res;
}

void solve() {
	cin >> n;
	vector<bool> pr(n + 100);
	auto p = erat(n + 10);
	for (auto i : p)
		pr[i] = true;

	set<ll> s;
	for (int i = 2; i < n + 2; i++)
		s.insert(2 - pr[i]);
	cout << s.size() << endl;

	for (int i = 2; i < n + 2; i++)
		cout << 2 - pr[i] << ' ';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}