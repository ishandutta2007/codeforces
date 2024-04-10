#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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
vector<ll> v;

void solve() {
	ll a, b, c, d, x, y, x1, y1, x2, y2;
	cin >> a >> b >> c >> d;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	x -= a;
	x += b;
	y -= c;
	y += d;
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && (x != x2 || x != x1 || a == 0 || b == 0) && (y != y2 || y != y1 || c == 0 || d == 0))
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