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

ll len(ll v) {
	ll res = 0;
	while (v)
		res++, v /= 10;
	return res;
}

void solve() {
	ll a, b, c;	
	cin >> a >> b >> c;
	ll g = 1;
	while (len(g) < c)
		g *= 10;
	ll va = g;
	ll vb = g;
	while (len(va) < a)
		va *= 2;
	while (len(vb) < b)
		vb *= 5;



	cout << va << ' ' << vb << '\n';	
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