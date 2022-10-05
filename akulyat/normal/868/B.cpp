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
	ll h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	h *= 5;
	t1 *= 5;
	t2 *= 5;
	h %= 60;
	t1 %= 60;
	t2 %= 60;
	t1 *= 3600;
	t2 *= 3600;
	ll hp = 3600 * h + 60 * m + s;  
	ll mp = 3600 * m + 60 * s;  
	ll sp = 3600 * s;

	if (t1 > t2)
		swap(t1, t2);
	bool ans = false;
	{
		bool lans = true;
		for (int i = t1 + 1; i < t2; i++) {
			if (i == hp) lans = false;
			if (i == mp) lans = false;
			if (i == sp) lans = false;
		}
		if (lans)
			ans = true;
	}
	{
		bool lans = true;
		for (int i = t2 + 1; i < t1 + 3600 * 60; i++) {
			if (i % (3600 * 60) == hp) lans = false;
			if (i % (3600 * 60) == mp) lans = false;
			if (i % (3600 * 60) == sp) lans = false;
		}
		if (lans)
			ans = true;
	}
	if (ans) 
		cout << "YES";
	else
		cout << "NO";
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