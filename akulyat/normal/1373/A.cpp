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
	ll a, b, c;
	cin >> a >> b >> c;
	ll v1a = a;
	ll v1b = c;
	ll vma = a * b;
	ll vmb = c;
	if (v1a < v1b)
		cout << 1 << ' ';
	else
		cout << -1 << ' ';
	if (vma > vmb)
		cout << b << ' ';
	else
		cout << -1 << ' ';
	cout << '\n';
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