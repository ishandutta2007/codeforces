#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<int, int> pint;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, i, j;
vector<ll> m;
bool viv = false;

bool far(ll a, ll b, ll r) {
	return (abs(a - b) >= r);
}

bool por(ll a, ll b, ll c) {
	if (a > b)
		return false;
	if (b > c)
		return false;
	return true;
}

bool por(ll a, ll b) {
	if (a > b)
		return false;
	return true;
}

void solve() {
	ll a, b, c, r;
	cin >> a >> b >> c >> r;
	if (por(b, a))
		swap(a, b);
	if (por(c, a, b)) {
		swap(a, b);
		c = -c;
		b = -b;
		a = -a;
	}

	if (viv)
		cout << a << ' ' << b << ' ' << c << ": ";
	if (por(a, b, c)) {
		ll res = b - max(a, c -  r);
		res = max(res, 0ll);
		res = b - a - res;
		cout << res << '\n';
		return;
	}
	ll res = c - max(c - r, a) + min(c + r, b) - c;
	res = b - a - res;
	cout << res << '\n';
}
 
int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}