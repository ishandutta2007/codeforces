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

ll h, m;
vector<ll> v;
bool viv = false;

void inter(int &a) {
	if (a == 0)
		return void(a = 0);
	if (a == 1)
		return void(a = 1);
	if (a == 8)
		return void(a = 8);
	if (a == 2)
		return void(a = 5);
	if (a == 5)
		return void(a = 2);
	return void(a = -1);
}

void pr(int a) {
	if (a <= 9)
		cout << "0";
	cout << a;
}

bool bad(int lh, int lm) {
	if (viv)
		cout << "\t\tbad(" << lh << ' ' << lm << ")" << endl;
	int a = lh / 10;
	int b = lh % 10;
	int c = lm / 10;
	int d = lm % 10;
	inter(a);
	inter(b);
	inter(c);
	inter(d);
	if (min(min(a, b), min(c, d)) == -1)
		return true;

	int slh = 10 * d + c;
	int slm = 10 * b + a;

	if (slh >= h || slm >= m)
		return true;

	pr(lh);
	cout << ":";
	pr(lm);
	cout << endl;

	return false;
}

void solve() {
	cin >> h >> m;
	string s;
	cin >> s;
	int lh, lm;
	lh = (s[0] - '0') * 10 + (s[1] - '0');
	lm = (s[3] - '0') * 10 + (s[4] - '0');

	if (viv)	
		cout << "\tstart " << lh << ' ' << lm << endl;

	while (bad(lh, lm)) {
		lm++;
		if (lm == m) {
			lm = 0;
			lh++;
			if (lh == h)
				lh = 0;
		}
	}
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