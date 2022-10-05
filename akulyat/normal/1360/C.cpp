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


void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	ll odd = 0;
	for (auto i: v)
		if (i & 1)
			odd++;

	bool res = false;
	if (!(odd & 1))
		res = true;
	for (int i = 1; i < n; i++)
		if (v[i] == v[i - 1] + 1)
			res = true;

	if (res)
		cout << "YES\n";
	else
		cout << "NO\n";

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