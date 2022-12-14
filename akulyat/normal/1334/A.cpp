#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n, m;
bool viv = false;
vector<ll> a, b;

void solve() {
	cin >> n;
	a.clear();
	b.clear();
	a.resize(n + 1);
	b.resize(n + 1);
	for (int i = 1; i < n + 1; i++) 
		cin >> a[i] >> b[i];

	bool good = true;
	for (int i = 1; i < n + 1; i++) {
		if (a[i] < a[i - 1])
			good = false;
		if (b[i] < b[i - 1])
			good = false;
		if ((a[i] - a[i - 1]) < (b[i] - b[i - 1]))
			good = false;
	}

	if (good)
		cout << "YES\n";
	else
		cout << "NO\n";

}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
  cin >> t;
	while (t--)
		solve();

	return 0;
}