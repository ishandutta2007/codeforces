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


ll n;
bool viv = false;
vector<ll> a, b;

void solve() {
	cin >> n;
	a.clear();
	b.clear();
	a.resize(n);
	b.resize(n);
	for (auto &i : a) 
		cin >> i;
	for (auto &i : b) 
		cin >> i;

	bool can = true;
	bool wp, wm;
	wp = wm = false;
	for (int i = 0; i < n; i++) {
		if (b[i] > 0 && !wp && (b[i] != 1 || a[i] != 1))
			can = false;
		if (b[i] < 0 && !wm && (b[i] != -1 || a[i] != -1))
			can = false;
		if (a[i] == 1)
			wp = true;
		if (a[i] == -1)
			wm = true;
		if (b[i] == 0 && (!wm || !wp) && a[i] != 0)
			can = false;
	}
	if (can)
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